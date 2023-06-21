#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>


int main(int argc, char** argv)
{   
    fflush(stdout);
    
    int sayi = (int)(argv[2][0]-48);
    
    int sayi2 = (int)(argv[2][1]-48);
    
    if(sayi2 >= 0)
    {
    	sayi = sayi*10 + sayi2;
    }
     
    printf("\n[hw1] %dsn boyunca %s calistirilacak...\n",sayi,argv[1]);  
    
    pid_t p_id;
    
    char* degisken[] = {argv[1],NULL};
    
    if((p_id = fork())!= 0)
    {  
        fflush(stdout);
        sleep(sayi);
        
        printf("\n\n[hw1] %d sn sona erdi %s kapatılıyor...\n",sayi,argv[1]);
        
        kill(p_id, SIGINT);
    }
    else
    {
        fflush(stdout);
        execv(argv[1],degisken);
    }
}
