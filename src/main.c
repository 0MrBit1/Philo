#include "../include/philo.h"


void philo_think(int philo_number , int time_think  )
{
    printf("philo number : %d , is thinking ");
    usleep(time_think);    
}

void philo_eat(int philo_number , int *forks , int time_eat , int total_forks)
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
    philo_think(int philo_number , int time_think  );
    philo_sleep(int philo_number , int time_sleep);
    
}

void philo_sleep(int philo_number , int time_sleep)
{
    printf("philo number : %d , is sleeping");
    usleep(time_sleep);
}

void Mr_philosopher(int philo_number , int **data )
{
    int number_of_times_eaten ;

    number_of_times_eaten =  0 ; 
    philo_eat(int philo_number , int *forks , int time_eat , int total_forks)
    philo_think(int philo_number , int time_think  );
    philo_sleep(int philo_number , int time_sleep);

}

int main(int argc , char **argv , char **env)
{
   //   1-number_of_philosophers    2-time_to_die    3-time_to_eat     4-time_to_sleep  5-[number_of_times_each_philosopher_must_eat]
   
   int **data ;
   int i ; 
   
   if (argc < 5)
   {
        perror("Number of arguments invalid");
        exit(EXIT_FAILURE);
    }

    data = malloc(sizeof(int*)*4);
    
    while (i < 4)
    {
        data[i] = malloc(sizeof(int)) ; 
        data[i] = argv[i + 1] ; 
    }
    i = 0 ; 

    while (i < 5)
    {

    }



}