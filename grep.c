#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <time.h>


char str[500];
char cpy[500];

int counter=0;
int line_no=0;

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

int main(int argc, char const *argv[])
{
	int i;
	clock_t begin = clock();
	while(1){
		
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
							strcpy(cpy,argv[2]);//strncpy(cpy, argv[2],1000);//
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
					for (int z = 0; z < 25; ++z)
					{
						char path_[100];
						strcpy(path_,argv[3]);
						//const char* extension="/10001.txt";
						char extension[]={'/',(char)49+z,'.','t','x','t'};
						strncat(path_, extension, (sizeof(path_) - strlen(path_)) );
						FILE *ptr;
						if((ptr=fopen(path_,"r"))==NULL){
							char path_1[100];
							strcpy(path_1,argv[3]);
							//const char* extension="/10001.txt";
							char extension[]={'/',(char)49+z/10,(char)(48+(z%10)),'.','t','x','t'};
							strncat(path_1, extension, (sizeof(path_1) - strlen(path_1)) );
							if((ptr=fopen(path_1,"r"))==NULL){
								printf("%s\n",path_1 );
								return 0;
							}

							
						}

						
						int line=0;
						line_no=0;
						while(!feof(ptr))
						{
							fgets(str,1000,ptr);/*fscanf(ptr,"%s",str);*/line_no++;
							for (i = 0; i < strlen(str); ++i)
							{
								if (str[i]==argv[2][0] || argv[2][0]=='?')
								{
									strcpy(cpy,argv[2]);//strncpy(cpy, argv[2],1000);//
									if(check(i,0)){
										printf("%d %s\n",line_no, str);counter++;break;
									}
								}
							}
						}
						clock_t end = clock();
						double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
						printf("%d, %f\n", counter,time_spent);
						
						
					}
					break;
				}
				//if no question mark
				else
				{
					for (int z = 0; z < 25; ++z)
					{
						char path_[100];
						strcpy(path_,argv[3]);
						//const char* extension="/10001.txt";
						char extension[]={'/',(char)49+z,'.','t','x','t'};
						strncat(path_, extension, (sizeof(path_) - strlen(path_)) );
						FILE *ptr;
						if((ptr=fopen(path_,"r"))==NULL){
							char path_1[100];
							strcpy(path_1,argv[3]);
							//const char* extension="/10001.txt";
							char extension[]={'/',(char)49+z/10,(char)(48+(z%10)),'.','t','x','t'};
							strncat(path_1, extension, (sizeof(path_1) - strlen(path_1)) );
							if((ptr=fopen(path_1,"r"))==NULL){
								printf("%s\n",path_1 );
								return 0;
							}

							
						}
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
				}
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
				for (int z = 0; z < 25; ++z)
				{
					char path_[100],path_1[100];
					strcpy(path_,argv[2]);
					//const char* extension="/10001.txt";
					char extension[]={'/',(char)49+z,'.','t','x','t'};
					strncat(path_, extension, (sizeof(path_) - strlen(path_)) );
					FILE *ptr
					if((ptr=fopen(path_,"r"))==NULL){
						//char path_1[100];
						strcpy(path_1,argv[2]);
						//const char* extension="/10001.txt";
						char extension[]={'/',(char)49+z/10,(char)(48+(z%10)),'.','t','x','t'};
						strncat(path_1, extension, (sizeof(path_1) - strlen(path_1)) );
						if((ptr=fopen(path_1,"r"))==NULL){
							printf("%s\n",path_1 );
							return 0;
						}

						
					}
					line_no=0;printf("%s\n",path_1 );
					while(!feof(ptr))
					{
						line_no++;
						fgets(str,1000,ptr);//getline(&str,ptr);//fscanf(ptr,"%s",str);
						if(strstr(str,argv[1]))
						{
							printf("%d %s\n",line_no, str);counter++;
						}
					}
					clock_t end = clock();
					double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
					printf("%d, %f\n", counter,time_spent);
				}
				break;
			}
		}
		printf("%d\n", counter);
	}
	return 0;
}