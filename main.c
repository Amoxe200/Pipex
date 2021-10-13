/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoxe <amoxe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 17:20:24 by amoxe             #+#    #+#             */
/*   Updated: 2021/10/13 16:43:52 by amoxe            ###   ########.fr       */
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
//         ld_one(f1, argv, end, ag);
//     child2 < 0)
//         return(perror("Fork : "));
//     // takes outfile and cmd2
//     if (child2 == 0)
//         child_two(f2, agtwo)&status, 0); // supervising the children 
//     waitpid(chic2, &status, // while they finish their tasks 
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
    // int f1;
    // int f2;
    int end[2];
    int status1;
    int status;

    pid_t child1;
    pid_t child2;

    t_list ag;

    pipe(end);
    if (ac != 5)
    {
        printf("Error In Args\n");
        exit(1);
    }
    // if (f1 < 0  || f2 < 0)
    // {
    //     printf("Error in file\n");
    //     return (-1);
    // }
    parser(argv, envp, &ag);

    child1 = fork();
    // child one takes infile and cmd1
    if (child1 == 0)
        child_one(9, argv, end, &ag, envp);
    close(end[1]);
    child2 = fork();
    // takes outfile and cmd2
    if (child2 == 0)
        child_two(5, &ag, end, argv, envp);


    dprintf(2, "za3im is the boss\n");
    close(end[0]); // parent
    close(end[1]); // it do nothing so close it
    waitpid(child1, &status1, 0); // supervising the children 
    if(WIFSIGNALED(status1))
{
    dprintf(2,"%dppppppppppppdppppppppppppppp\n",WTERMSIG(status));
} 
    waitpid(child2, &status, 0); // while they finish their tasks
     if(WIFSIGNALED(status1))
{
    dprintf(2,"%dppppppppppppdppppppppppppppp\n",WTERMSIG(status));
} 
    return (0);
}