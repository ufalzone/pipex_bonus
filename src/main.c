/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 23:29:52 by ufalzone          #+#    #+#             */
/*   Updated: 2025/02/09 19:02:21 by ufalzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_perror(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

int	open_file(char *file, int index)
{
	int	fd;

	if (index == 0)
	{
		fd = open(file, O_RDONLY);
		if (fd == -1)
		{
			perror("Error: cannot read input file");
			return (-1);
		}
	}
	else if (index == 1)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	return (fd);
}

char	*find_command_path(char *cmd, char **env)
{
	char	**paths;
	char	*path_line;
	char	*full_path;
	int		i;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5))
		i++;
	if (!env[i])
		return (NULL);
	path_line = env[i] + 5;
	paths = ft_split(path_line, ':');
	if (!paths)
		return (free_split(paths), NULL);
	i = 0;
	while (paths[i])
	{
		full_path = ft_strjoin_three(paths[i], "/", cmd);
		if (access(full_path, X_OK) == 0)
			return (free_split(paths), full_path);
		free(full_path);
		i++;
	}
	return (free_split(paths), NULL);
}

void	exec_cmd(char *str, char **env, int *p_fd)
{
	char	*cmd_path;
	char	**cmd_args;
	int		execve_status;

	cmd_args = ft_split(str, ' ');
	if (!cmd_args)
		ft_perror("Split failed");
	cmd_path = find_command_path(cmd_args[0], env);
	if (!cmd_path)
	{
		free_split(cmd_args);
		exit(127);
		perror("Command not found");
	}
	execve_status = execve(cmd_path, cmd_args, env);
	if (execve_status == -1)
	{
		free_split(cmd_args);
		free(cmd_path);
		ft_perror("Execve failed");
	}
}

void	create_pipe(char *str, char **env)
{
	int		p_fd[2];
	pid_t	pid;

	if (pipe(p_fd) == -1)
		ft_perror("Pipe failed");
	pid = fork();
	if (pid == -1)
		ft_perror("Fork failed");
	if (pid == 0)
	{
		close(p_fd[0]);
		dup2(p_fd[1], STDOUT_FILENO);
		close(p_fd[1]);
		exec_cmd(str, env, NULL);
	}
	else
	{
		waitpid(pid, NULL, 0);
		close(p_fd[1]);
		dup2(p_fd[0], STDIN_FILENO);
		close(p_fd[0]);
	}
}

int	here_doc(char *limiter, int ac)
{
	int		p_fd[2];
	char	*current;
	char	*limiter_n;

	if (ac < 6)
		ft_perror("Usage: ./pipex here_doc LIMITER cmd1 cmd2 ... cmdn file");
	if (pipe(p_fd) == -1)
		ft_perror("Pipe failed");
	limiter_n = ft_strjoin(limiter, "\n");
	while (1)
	{
		current = get_next_line(0);
		if (!current || ft_strcmp(current, limiter_n) == 0)
		{
			free(current);
			break;
		}
		write(p_fd[1], current, ft_strlen(current));
		free(current);
	}
	close(p_fd[1]);
	return (p_fd[0]);
}

void	check_command(char **av, int ac)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i][0] == '\0')
			ft_perror("Command is empty");
		i++;
	}
}

void	pipex(int ac, char **av, char **env)
{
	int	fd;
	int	i;
	int	mode;

	i = 2;
	if (ft_strcmp(av[1], "here_doc") == 0)
	{
		if (ac < 6)
			ft_perror("Usage: ./pipex here_doc LIMITER cmd1 cmd2 outfile");
		fd = here_doc(av[2], ac);
		mode = 2;
		i ++;
	}
	else
	{
		fd = open_file(av[1], 0);
		mode = 1;
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	while (i < ac - 2)
		create_pipe(av[i++], env);
	fd = open_file(av[ac - 1], mode);
	if (fd == -1)
		ft_perror("Error: cannot open file");
	dup2(fd, STDOUT_FILENO);
	close(fd);
	exec_cmd(av[ac - 2], env, NULL);
}

int	main(int ac, char **av, char **env)
{
	int	fd_original[2];
	int	i;

	if (ac < 5)
		ft_perror("Usage: ./pipex file1 cmd1 ... cmd file2");
	check_command(av, ac);
	pipex(ac, av, env);
	return (0);
}
