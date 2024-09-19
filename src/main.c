#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>


void philo_think(int philo_number , int time_think  )
{
    //printf("philo number : %d , is thinking ");
    usleep(time_think);    
}

void philo_sleep(int philo_number , int time_sleep)
{
    //printf("philo number : %d , is sleeping");
    usleep(time_sleep);
}

void philo_eat(int philo_number , int *forks , int time_eat , int total_forks  , int time_think , int time_sleep )
{

    if (philo_number == 0)
    {
        forks[philo_number]  =   0 ;
        forks[total_forks - 1] = 0 ;  
    }
    else if (philo_number == total_forks - 1)
    {
        forks[philo_number]  =   0 ;
        forks[0] = 0 ;  
    }
    else 
    {
        forks[philo_number]  =   0 ;
        forks[philo_number - 1 ] = 0 ; 

    }
    //take_two_forks ; 
    usleep(time_eat) ;
    philo_think( philo_number ,  time_think  );
    philo_sleep( philo_number , time_sleep);

}

void Mr_philosopher(int philo_number , int *forks , int time_eat , int time_think ,int time_sleep , int total_forks )
{
    int number_of_times_eaten ;

    number_of_times_eaten =  0 ; 
   philo_eat(philo_number , forks , time_eat ,  total_forks  ,  time_think ,  time_sleep ) ; 

}

int main(int argc , char **argv , char **env)
{
   //   1-number_of_philosophers    2-time_to_die    3-time_to_eat     4-time_to_sleep  5-[number_of_times_each_philosopher_must_eat]
   
   int **data ;
   int i ; 
   
   if (argc < 5 || argc > 6 )
   {
        perror("Number of arguments invalid");
        exit(EXIT_FAILURE);
    }
    i = 1 ; 
    data = malloc(sizeof(int*) * (argc - 1 ));
    
    while (i < argc - 1 )
    {
        data[i] = malloc(sizeof(int)) ; 
        data[i][0] = atoi ( argv[i + 1] )  ; 
    }
    data[i] = malloc(sizeof(int)* atoi( argv[1] )  ) ;

 



}