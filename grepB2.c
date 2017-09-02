#include <malloc.h>
#include <time.h>
#include <stdlib.h>
#include<stdio.h>
#include<string.h>
#include  <sys/types.h>
#include<dirent.h>
#include<sys/stat.h>
#include<unistd.h>
#include<sys/wait.h>

char str[500], cpy[500],filename[1000];
int counter=0,file_no=0,line_no=0,argc;
char const **argv;

DIR *directory;
struct dirent* file;


int	 check(int j,int z){
	for (int i = 0; i < strlen(cpy) - z; ++i)
	{
		if (cpy[z+i]=='?')
		{
			int q=check(i+j,z+i+1);
			if (q==1)
			{
				return 1;
			}
			else if ((str[i+j] < 123 && str[i+j] > 96) || (str[i+j] > 47 && str[i+j] < 58))
			{
				return check(i+j+1,z+i+1);
			}
			else{
				return 0;
			}
		}
		else if (str[i+j]==cpy[z+i])
		{
			continue;
		}
		else{
			return 0;
		}
	}
	return 1;
}
void check_1(){int i;
	clock_t begin = clock();FILE *ptr=fopen(filename,"r");int line=0;
	line_no=0;
	sprintf(filename, "%s/%s", "output/", file->d_name);
	FILE* ptr1=fopen(filename,"w");			
		while(!feof(ptr))
	{
		fgets(str,1000,ptr);/*fscanf(ptr,"%s",str);*/line_no++;
		for (i = 0; i < strlen(str); ++i)
		{
			if (str[i]==argv[2][0] || argv[2][0]=='?')
			{
				strcpy(cpy,argv[2]);//strncpy(cpy, argv[2],1000);//
				if(check(i,0)){
					fprintf(ptr1,"%d %s\n",line_no, str);
					counter++;
					break;
				}
			}
		}
	}
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%d, %f\n", counter,time_spent);
}
void check_(){
while(1){int i;
		
		if (!(strcmp(argv[1],"-E")))
		{
			if (argc==3)
			{
				scanf("%s",str);
				if (strchr(argv[2],'?'))
				{
					for (i = 0; i < strlen(str); ++i)
					{
						if (str[i]==argv[2][0])
						{
							strcpy(cpy,argv[2]);
							if(check(i,0))
							{
								counter++;
								printf("%s\n",str);counter++;	
								break;
							}
						}
					}
				}
				//if no question mark
				else
				{
					if(strstr(str,argv[2]))
					{
						printf("%s\n",str);counter++;
					}
				}
			}
			else{
				if (strchr(argv[2],'?'))
				{
					
					directory=opendir(argv[3]);
					if (directory==NULL)
					{
						printf("Not a directory\n");
						return;
					}
					while ((file=readdir(directory)) != NULL) {
        				//printf("%s\n", file->d_name);
        				if( strstr(file->d_name, ".txt")){
						printf("%s\n",file->d_name);file_no++;
        					
        					sprintf(filename, "%s/%s", argv[3], file->d_name);
							
							pid_t pid = fork();

							   if (pid == -1) {
							    perror("fork failed");
							    exit(EXIT_FAILURE);
							   }
							   else if (pid == 0) {
								check_1();
							    _exit(EXIT_SUCCESS);
							   }
							   else {
							    int status;
							    (void)waitpid(pid, &status, 0);
							   }
							
						}
					}
					printf("\nTotal no of files :%d\n", file_no);
					break;
				}
				//if no question mark
				else
				{
					FILE *ptr=fopen(argv[3],"r");
					fgets(str,1000,ptr);//fgets(str,1000,ptr);//fscanf(ptr,"%s",str);
					line_no=0;
					while(!feof(ptr))
					{
						/*int x=0;
						printf("%d\n",++x );*/
						line_no++;
						if(strstr(str,argv[2]))
						{
							printf("%d %s",line_no, str);counter++;
						}
						fgets(str,1000,ptr);//getline(&str,ptr);//fscanf(ptr,"%s",str);
					}printf("%d\n", counter);
					break;
				}
			}
		}
		else
		{
			if (argc==2)
			{
				scanf("%s",str);
				if(strstr(str,argv[1]))
				{
					printf("%s\n",str);counter++;
				}
			}
			else if (argc==3)
			{
				FILE *ptr=fopen(argv[2],"r");
				line_no=0;
				while(!feof(ptr))
				{
					line_no++;
					fgets(str,1000,ptr);//getline(&str,ptr);//fscanf(ptr,"%s",str);
					if(strstr(str,argv[1]))
					{
						printf("%d %s\n",line_no, str);counter++;
					}
				}
				/*clock_t end = clock();
				double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
				printf("%d, %f\n", counter,time_spent);*/
					
				break;
			}
		}
		printf("%d\n", counter);
	}
}

int main(int argcm, char const *argvm[])
{
	argv=argvm;
	argc=argcm;
	check_();
	DIR *directory;
	struct dirent* file;
	directory=opendir("/mnt/d/Sem 5/CS 310/Assign2_B15303/output");
	if (directory==NULL)
	{
		printf("Not a directory\n");
		return 0;
	}
	while ((file=readdir(directory)) != NULL) {
		char filename[1000], src[]=" ",sls[]="/";
		sprintf(filename, "%s/%s", argv[3], file->d_name);
		if( strstr(file->d_name, ".txt"))
		{

			strcat(filename, src);
			strcat(filename, argv[3]);
			strcat(filename, sls);
			strcat(filename, file->d_name);
		}
		else
			continue;
		
	}
	pid_t pid = fork();
	if (pid == -1)
	{
        perror("fork failed");
        exit(EXIT_FAILURE);
    }
	else if (pid == 0) {
		char *ak[]={"cat",filename,NULL};
		execvp(ak[0],ak);
		_exit(EXIT_SUCCESS);
	}
	else {
  		int status;
  		(void)waitpid(pid, &status, 0);
		}
	return 0;
}











