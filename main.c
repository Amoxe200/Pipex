/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoxe <amoxe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 17:20:24 by amoxe             #+#    #+#             */
/*   Updated: 2021/10/11 18:48:09 by amoxe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"


void pipex(int f1, int f2, t_list ag)
{
    // parse data save it in a struct
    int end[2];
    int status;
    pid_t child1;
    pid_t child2;

    pipe(end);
    child1 = fork();
    if (child1 < 0)
        return(perror("Fork : "));
    // child one takes infile and cmd1
    if (child1 == 0)
        child_one(f1, ag.my_cmd[0]);
    child2 = fork();
    if (child2 < 0)
        return(perror("Fork : "));
    // takes outfile and cmd2
    if (child2 == 0)
        child_two(f2, ag.my_cmd[1]);

    waitpid(child1, &status, 0); // supervising the children 
    waitpid(child2, &status, 0); // while they finish their tasks 
    close(end[0]); // parent
    close(end[1]); // it do nothing so close it
     
}

void parser(char **argv, char **envp, t_list ag)
{
    
     // retrieve the path line from envp 
    ag.path_envp =  find_path(envp);
    // retrieve all the possible path from envp
    ag.my_path = ft_split(ag.path_envp, ':');
    // split cmd1
    ag.my_cmd = ft_split(argv[2], ' ');
    // split second command
    
}

int comp_str(char *str1, char *str2)
{
    int i;

    i = 0;
    while (str2[i])
    {
        if (str1[i] != str2[i])
            return (0);
        i++;
    }
    return (1);
}

char *find_path(char  **envp)
{
    int d;
    char *str;
    char *path;
    
    d = 0;
    while (envp[d])
    {
        str = envp[d];
        if (ft_strlen(str) >= 5 && comp_str(str, "PATH="))
                path = str;
        d++;
    }
    return (path);
}

int main(int ac, char **argv, char **envp)
{
    int f1;
    int f2;

    t_list ag;
    if (ac != 5)
    {
        printf("Error In Args\n");
        exit(1);
    }
    f1 = open(argv[1], O_RDONLY, 0644);
    f2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
            printf("f1 = %d f2 =%d\n", f1, f2);
    if (f1 < 0  || f2 < 0)
    {
        printf("Error in file\n");
        return (-1);
    }
    parser(argv, envp, ag);
    pipex(f1, f2, ag);
    return (0);
}