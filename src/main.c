#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

struct thread_data
{
    int philo_number;
    int *forks;
    int time_die ; 
    int time_eat;
    int time_sleep;
    int total_forks; 
}; 

void philo_sleep(int philo_number , int time_sleep)
{
    printf("philo number ; %d is sleeping \n" , philo_number); 
    usleep(time_sleep);
}

void philo_eat(struct thread_data *philo_data )
{

    int philo_number ;
    int *forks  ;
    int time_eat ;
    int total_forks ;
    int time_sleep  ;

    philo_number =   philo_data-> philo_number    ;
    time_eat  =      philo_data-> time_eat    ;
    total_forks =   philo_data-> total_forks    ;
    time_sleep  =   philo_data-> time_sleep     ;

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


    if (philo_number == 0)
    {
        forks[philo_number]  =   1 ;
        forks[total_forks - 1] = 1 ;  
    }
    else if (philo_number == total_forks - 1)
    {
        forks[philo_number]  =   1 ;
        forks[0] = 1 ;  
    }
    else 
    {
        forks[philo_number]  =   1 ;
        forks[philo_number - 1 ] = 1 ; 

    }
    philo_sleep( philo_number , time_sleep);

}

void Mr_philosopher(struct thread_data *philo_data )
{
    int number_of_times_eaten ;

    number_of_times_eaten =  0 ; 
    
    philo_eat(philo_data) ; 

}

int main(int argc , char **argv , char **env)
{
   //   1-number_of_philosophers    2-time_to_die    3-time_to_eat     4-time_to_sleep  5-[number_of_times_each_philosopher_must_eat]
   
   int i;
   int number_of_philosophers ;
   struct thread_data *philo_data ;  
   
   if (argc < 5 || argc > 6 )
   {
        perror("Number of arguments invalid");
        exit(EXIT_FAILURE);
    }
    number_of_philosophers = atoi(argv[1]) ; 
    
    philo_data = malloc(  sizeof(struct thread_data) ) ;
    philo_data-> forks  = malloc(  sizeof(int)  *  (  argc - 1)     )       ;
    philo_data->time_die = argv[2] ; 
    philo_data -> time_eat  =   argv[3]     ; 
    philo_data-> time_sleep  =  argv[4]   ;
    philo_data-> total_forks =   argc - 1   ; 

    philo_data->philo_number


}