/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoxe <amoxe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 17:20:24 by amoxe             #+#    #+#             */
/*   Updated: 2021/10/09 12:43:39 by amoxe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"


// void pipex(int f1, int f2, char **argv, char **envp)
// {
//        // parse data save it in a struct  
    
//     int end[2];
//     int status;
//     pid_t child1;
//     pid_t child2;

//     pipe(end);
//     child1 = fork();
//     if (child1 < 0)
//         return(perror("Fork : "));
//     // child one takes infile and cmd1
//     if (child1 == 0)
//         child_one();
//     child2 = fork();
//     if (child2 < 0)
//         return(perror("Fork : "));
//     // takes outfile and cmd2
//     if (child2 == 0)
//         child_two();

//     close(end[0]); // parent
//     close(end[1]); // it do nothing so close it
//     waitpid(child1, &status, 0); // supervising the children 
//     waitpid(child2, &status, 0); // while they finish their tasks 
     
// }

// void parser(int ac, char **argv, char **envp)
// {
//     char **path_envp;
//     char **my_path;
//     char **my_cmd;
//     // retrieve the path line from envp 
// }

char *find_nvp(char **envp)
{
    int i;
    char *str;
    
    i = 0;
    while (envp[i])
    {
        str = envp[i];
        i++;
    }
    printf("%s\n", str);
    return (str);
}

int main(int ac, char **argv, char **envp)
{
    int f1;
    int f2;

    (void)ac;
    (void)argv;
    (void)envp;
    f1 = open(argv[1], O_RDONLY);
    f2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
    if (f1 < 0  || f2 < 0)
        return (-1);
    find_nvp(envp);
   // parser(ac, argv, envp);
    //pipex(f1, f2, argv, envp);
    return 0;
}