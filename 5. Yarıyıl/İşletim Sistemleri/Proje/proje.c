#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <termios.h>
#include <ctype.h>

#define MAXSATIR 512 //Desteklenen maksimum karakter sayısı
#define clear() printf("\033[H\033[J")//clear() fonksiyonu
#define READ  0
#define WRITE 1

#define MAG   "\x1B[35m"
#define RESET "\x1B[0m"

static char* currentDirectory;
static int calistir(char* args[MAXSATIR], char* kmt);

void baslangic() 
{ 
    clear(); 
    printf("**********B Şubesi 1. Grup Kabuk Projesi**********\n"); 
}

char *komutlar[]={
	"cd",
	"help",
	"quit",
	"clear"
};

int komutSayisi = sizeof(komutlar)/sizeof(char *);

int komutCd(char **args)
{
	if (args[1]==NULL)
	{
		fprintf(stderr,"Uyarı:\"cd\" komutundan sonra dosya bilgisi giriniz.\n");
	}
	else
	{
		if (chdir(args[1])!=0)
		{
			perror("Hata");
		}
	}
	return 1;
}

int komutHelp(char **args)
{
	int i;
	printf("Isletim Sistemleri Projesi\n");
	for (i=0;i<komutSayisi;i++)
	{
		printf("%s\n",komutlar[i]);		
	}
	printf("Kabuğumuzda LINUX işletim sisteminin sağladığı diğer komutlarda kullanılabilmektedir.\nBu komutların ne işe yaradığını man komutu yardımıyla öğrenebilirsiniz\n");
	return 1;
}

int komutQuit(char **args)
{
	int durum;
	while (!waitpid(-1,&durum,WNOHANG)){}
	exit(0);
}
void komutClear(char **args)
{
	clear();
}

int komutBatch(char *dosyaAdi)
{
	char *dsy;
    	char satir[2048] = {0};
    	unsigned int line_count = 0;
    	dsy = dosyaAdi;
    	char *args[MAXSATIR];
    
    	FILE *dosya = fopen(dsy, "r");
    
    	if (!dosya)
    	{
        	fprintf(stderr,"Uyarı: Batch dosyası bulunamadı.\n");
        	return EXIT_FAILURE;
    	}
    
    	while (fgets(satir, 2048, dosya))
    	{
        	int boyut = strlen(satir);
		if(boyut > 513)
		{
			fprintf(stderr, "Uyarı: Kabuk programı için yanlış sayıda komut satırı argümanı (512 karakterden fazla).\n");
		}
		else
		{
        		printf("%s", satir);
			char *temp = strtok(satir, ";");
			while(temp != NULL) 
			{
        			calistir(args, temp);
    				temp = strtok(NULL, ";");
    			}
        	
        		if (satir[strlen(satir) - 1] != '\n')
            		printf("\n");
            	}
    	}
    	exit(0);
    	fclose(dosya);
}


static int n = 0; 
static int komut(char* args[MAXSATIR])
{
	int pid;
	int durum;	
 	
	pid = fork();

	if (pid == 0) {
		execvp(args[0], args);
		if (execvp( args[0], args) == -1)
		{
		 	if(strcmp(args[0], "cd") != 0 && strcmp(args[0], "quit") != 0 && strcmp(args[0], "help") != 0 && strcmp(args[0], "clear") != 0 && strcmp(args[0], "bh") != 0 )
		 	{
		 		fprintf(stderr, "Uyarı: Komut yok veya komut yürütülemez.\n");
		 	}
			_exit(EXIT_FAILURE); 
		}	
	}
	else if (pid < 0)
	{
		perror("myShell: ");
	}
	else
	{
		wait(&durum);
	} 
	return pid;
}

static char* boslukSilme(char* s)
{
	while (isspace(*s)) ++s;
	return s;
}
 
static void parcala(char* args[MAXSATIR], char* kmt)
{
	kmt = boslukSilme(kmt);

	char* next = strchr(kmt, ' ');
	int i = 0;
	

	while(next != NULL) 
	{
		next[0] = '\0';
		args[i] = kmt;
		++i;
		kmt = boslukSilme(next + 1);
		next = strchr(kmt, ' ');
	}
	
	int kontrol = strlen(kmt);
	if (kmt[0] != '\0') 
 	{
		if(kmt[kontrol - 1] != '\0')
 		{	
 			strcat(kmt, "\n");
 		}
		args[i] = kmt;
		next = strchr(kmt, '\n');
		next[0] = '\0';
		++i; 
	}
	args[i] = NULL;
}

static int calistir(char* args[MAXSATIR], char* kmt)
{
	parcala(args, kmt);
	if (args[0] != NULL) {
		if (strcmp(args[0], "cd") == 0) komutCd(args);
		else if (strcmp(args[0], "help") == 0) komutHelp(args);
		else if (strcmp(args[0], "quit") == 0) komutQuit(args);
		else if (strcmp(args[0], "clear") == 0) komutClear(args);
		n += 1;
		return komut(args);
	}
	return 0;
}

static void kaldir(int n)
{
	int i;
	for (i = 0; i < n; ++i) 
		wait(NULL); 
}

void ctrl(int sig)
{
    if(sig == SIGINT){}
    else if(sig == SIGQUIT){}
    else if(sig == SIGTSTP){}
    else
    {
        printf("Farkli bir signal algilandi");
    }
}

char satir[2048];

void prompt()
{
	char *args[MAXSATIR];
	
	baslangic();
	
	while (1) {
		printf(MAG " %s > " RESET, getcwd(currentDirectory, MAXSATIR));
		signal(SIGINT, ctrl);
    		signal(SIGTSTP, ctrl);
    		signal(SIGQUIT, ctrl);
		
		if(!fgets(satir,2048,stdin))
		{
			if(satir!="EOT")
			{
				exit(0);
			}
		}
		
		int boyut = strlen(satir);
		if(boyut > 513)
		{
			fprintf(stderr, "Uyarı: Çok uzun bir komut satırı (512 karakterden fazla).\n");
		}
		else
		{	
			char *temp = strtok(satir, ";");
			while(temp != NULL) 
			{
        			calistir(args, temp);
    				temp = strtok(NULL, ";");
    			}
    			kaldir(n);
			n = 0;
		}

	}
}

int main(int argc, char *argv[])
{
	if(argc == 1)
	{
		prompt();
	}
	else if(argc == 2)
	{
		komutBatch(argv[1]);
	}
	else
	{
	 	printf("Geçersiz parametre\n");
	}
	return EXIT_SUCCESS;
}
