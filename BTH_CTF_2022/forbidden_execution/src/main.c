#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *print_function(int auth, char* buffer){
	printf("[+] Printing flag:\n");
	printf("%s\n",buffer);
	if (auth != 1){
		printf("[-] Not authorized to continue. Exiting\n");
		exit(0);
	}
	return buffer;
}

int stop(int value){
	if (value != 5){
		printf("[-] Not authorized to continue. Exiting\n");
		exit(0);
	}
	return value;
}


int hex_to_int(char c)
{
    if (c >= 97)
        c = c - 32;
    int first = c / 16 - 3;
    int second = c % 16;
    int result = first * 10 + second;
    if (result > 9) result--;
    return result;
}
int hex_to_ascii(char c, char d){
        int high = hex_to_int(c) * 16;
        int low = hex_to_int(d);
        return high+low;
}



void add_chars(char *buffer, char* new, int algorithm){
	if (algorithm ==255-254){
		//reverse
		size_t l = strlen(new);
		char* r = (char*)malloc((l + 1) * sizeof(char));
		r[l] = '\0';
		int i;
		for(i = 0; i < l; i++) {
			r[i] = new[l - 1 - i];
		}
		
		//hex2ascii
		int length = strlen(r);
		char buf = 0;
		for(i = 0; i < length; i++){
			if(i % 2 != 0){
				char xd[20];
				sprintf(xd,"%c", hex_to_ascii(buf, r[i]));
				strcat(buffer,xd);
			}else{
				buf = r[i];
			}
		}

		free(r);
	}else if (algorithm ==1*2){
		char *p = new;
		while (*p) { // While there are more characters to process...
			if ( isdigit(*p) || ( (*p=='-'||*p=='+') && isdigit(*(p+1)) )) {
				// Found a number
				int val = strtol(p, &p, 10); // Read number
				char xd[20];
				sprintf(xd,"%c", val/2); // and print it.
				strcat(buffer,xd);
			} else {
				// Otherwise, move on to the next character.
				p++;
				}
			}
			

	}else if (algorithm ==81/9/3){
		 //hex2ascii
                int length = strlen(new);
                char buf = 0;
		int i;
                for(i = 0; i < length; i++){
                        if(i % 2 != 0){
                                char xd[20];
                                sprintf(xd,"%c", 5^hex_to_ascii(buf, new[i]));
                                strcat(buffer,xd);
                        }else{
                                buf = new[i];
                        }
                }




	}else{
		printf("[-] Not authorized to continue. Exiting\n");
		exit(0);

	}
}

int main(){
	int auth = 0; 
	char flag[100];
	memset(flag,0,100);
	char *secret1 ="463333e4f5038475"; //hex + reverse
	char *secret2 ="x230x190x166x102x134x170x164x146"; //decimal  * 2
	char *secret3 ="515c5a473141424056"; //hex xor 5

	strcat(flag,"BTH");

	print_function(auth, flag);
	strcat(flag,"_CTF{");
	print_function(auth, flag);

	stop(auth); //change to auth
	add_chars(flag, secret1,1);
	print_function(auth, flag);

	if (auth != 9){
                printf("[-] Not authorized to continue. Exiting\n");
                exit(0);
        }

	
	add_chars(flag, secret2,2);
	add_chars(flag, secret3,3);
	strcat(flag,"}");
	print_function(auth, flag);


	return 0;
}
