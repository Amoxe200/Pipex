/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoxe <amoxe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 17:20:24 by amoxe             #+#    #+#             */
/*   Updated: 2021/10/12 21:26:50 by amoxe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"


// void pipex(int f1, int f2, t_list ag, char **argv)
// {
//     // parse data save it in a struct
//     int end[2];
//     int status;
//     pid_t child1;
//     pid_t child2;
    
//     pipe(end);

//     child1 = fork();
//     if (child1 < 0)
//         return(perror("Fork : "));
//     // child one takes infile and cmd1
//     //if (child1 == 0)
//         child_one(f1, argv, end, ag);
//     child2 = fork();
//     if (child2 < 0)
//         return(perror("Fork : "));
//     // takes outfile and cmd2
//     if (child2 == 0)
//         child_two(f2, ag.cmd_two);

//     waitpid(child1, &status, 0); // supervising the children 
//     waitpid(child2, &status, 0); // while they finish their tasks 
//     dup2(f2, STDOUT_FILENO);
//     dup2(end[0], STDIN_FILENO);
//     close(end[0]); // parent
//     close(end[1]); // it do nothing so close it
//     close(f2);
//     exit(EXIT_FAILURE);
// }

void parser(char **argv, char **envp, t_list *ag)
{
     // retrieve the path line from envp 
    ag->path_envp =  find_path(envp);
    // retrieve all the possible path from envp
    ag->my_path = ft_split(ag->path_envp, ':');
    // split cmd1
    ag->my_cmd = ft_split(argv[2], ' ');
    // split second command
    ag->cmd_two = ft_split(argv[3], ' ');

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
    if (f1 < 0  || f2 < 0)
    {
        printf("Error in file\n");
        return (-1);
    }
    parser(argv, envp, &ag);


     int end[2];
    int status;
    pid_t child1;
    pid_t child2;
    
    pipe(end);

    child1 = fork();
    // child one takes infile and cmd1
    if (child1 == 0)
    {
        // int i;
	    // char *cmd;
	
	    // i = -1;
	    dup2(f1, STDIN_FILENO);
	    dup2(end[1], STDOUT_FILENO);
        execvp(ag.my_cmd[0],ag.my_cmd);
     
       exit(1);
    }
    close(end[1]);
    child2 = fork();

    // takes outfile and cmd2
    if (child2 == 0)
        {
                
        // int i;
	// char *cmd;
	
	// i = -1;

	
	 dup2(end[0], STDIN_FILENO);
	 dup2(f2, STDOUT_FILENO);
       execvp(ag.cmd_two[0],ag.cmd_two);
    exit(2);
        }

    waitpid(child1, &status, 0); // supervising the children 
    waitpid(child2, &status, 0); // while they finish their tasks
    
    close(end[0]); // parent
    close(end[1]); // it do nothing so close it
    close(f2);
    exit(EXIT_FAILURE);
 
    return (0);
}