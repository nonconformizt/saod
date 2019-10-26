#include <iostream>
#include <string.h>
using namespace std;


#define IN_ZONE(x) ((x + 256) % 256 >= ZONE_START || (x + 256) % 256 <= ZONE_END)

// параметры запрещенной зоны
const int ZONE_START = 243;
const int ZONE_END = 31;
const int ZONE_LEN = 45;

void show_help();
void encrypt(u_char * msg, int msg_n, u_char * key, int key_n);
void decrypt(u_char * msg, int msg_n, u_char * key, int key_n);
void rand_str(u_char * str, int len);
void testing(int msg_len, int msg_count, int key_len);

int main(int argc, char *argv[])
{
    int msg_len = 20;
    int msg_count = 100;
    int key_len = 6;

	for (int i = 0; i < argc; ++i) 
    {
        if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) 
        {
            show_help();
            return 0;
        }
        else if (strcmp(argv[i], "-l") == 0 || strcmp(argv[i], "--length") == 0)
        {
            msg_len = atoi(argv[++i]);
        }
        else if (strcmp(argv[i], "-c") == 0 || strcmp(argv[i], "--count") == 0)
        {
            msg_count = atoi(argv[++i]);
        }
        else if (strcmp(argv[i], "-k") == 0 || strcmp(argv[i], "--key") == 0)
        {
            key_len = atoi(argv[++i]);
        }
    }

    testing(msg_len, msg_count, key_len);

}


void testing(int msg_len, int msg_count, int key_len)
{
    u_char msg[msg_len];
    u_char tmp[msg_len];
    u_char key[key_len];

    int fail_count = 0;

    for (int i = 0; i < msg_count; i++)
    {
        rand_str(msg, msg_len);
        rand_str(key, key_len);
        memcpy(tmp, msg, msg_len);

        cout << "\nMessage: \n";
        for (int j = 0; j < msg_len; j++) cout << (int) msg[j] << " ";
        
        cout << "\nKey: \n";
        for (int j = 0; j < key_len; j++) cout << (int) key[j] << " ";
        
        encrypt(msg, msg_len, key, key_len);

        cout << "\nEncrypted: \n";
        for (int j = 0; j < msg_len; j++) cout << (int) msg[j] << " ";

        decrypt(msg, msg_len, key, key_len);
        
        cout << "\nMessage: \n";
        for (int j = 0; j < msg_len; j++) cout << (int) msg[j] << " ";

        if (!memcmp(msg, tmp, msg_len))
            printf("\nTEST PASSED");
        else {
            printf("\n!!!!TEST FAILED");
            fail_count++;
        }


    }
    cout << "\n==============\n"
         << "FAILED " << fail_count << " OF " << msg_count << endl;
}


void show_help()
{
    cout << "ARGUMENTS: \n"
         << "-c --count    how many times repeat the test\n"
         << "              100 by default\n"
         << "-l --length   length of the test message \n"
         << "              20 by default\n"
         << "-k --key      length of the test key \n"
         << "              6 by default\n"
         << "-h --help     display this help and exit\n";
}


void encrypt(u_char * msg, int msg_n, u_char * key, int key_n)
{
    int key_tmp, 
        sign; // в какую сторону смещение

    for (int i = 0, key_i = 0; i < msg_n; i++, key_i = (key_i + 1) % key_n)
    {
        if (!IN_ZONE(msg[i]))
        {
            key_tmp = key[key_i] % ZONE_LEN;

            sign = 2*(key[key_i] % 2) - 1; // -1 если четное, +1 если нечетное

            msg[i] += sign * key_tmp;
            if (IN_ZONE(msg[i]))
                msg[i] += sign * ZONE_LEN;
        }
    }
}


void decrypt(u_char * msg, int msg_n, u_char * key, int key_n)
{
    int key_tmp,
        sign; // в какую сторону смещение

    for (int i = 0, key_i = 0; i < msg_n; i++, key_i = (key_i + 1) % key_n)
    {
        if (!IN_ZONE(msg[i]))
        {
            sign = 2*(key[key_i] % 2) - 1; // -1 если четное, +1 если нечетное
            
            key_tmp = key[key_i] % ZONE_LEN;

            msg[i] -= sign * key_tmp;
            if (IN_ZONE(msg[i]))
                msg[i] -= sign * ZONE_LEN;
            
        }
    }
}


void rand_str(u_char * str, int len)
{
    for (int i = 0; i < len; i++)
        str[i] = rand() % 255;   
}