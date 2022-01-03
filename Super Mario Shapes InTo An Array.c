#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
//// Megethos Pinaka ////
#define height 20
#define width 100

//// Dilwsh Synarthsewn Kai Global Metavlitwn ////
void print_array(char **array);
void draw();
int menu(int choose);
void designs();
char **array;     //Pinakas Deikths Se (2D)Pinaka Ektypwsis
int epilogi,thesi,y,M;
int *checkarray; //Pinakas Deikths Se Pinaka Elegxou


int main()
{
    int i, j;
    char para;
//// ZHTAME DYNAMIKA XWRO APO TO SYSTHMA KAI PAIRNOYME PISW (PINAKA) DIKTH TYPOY CHAR////////
    array = (char **) malloc(height * sizeof(char *));
    for (i = 0; i < height; i++) array[i] = (char *) malloc(width * sizeof(char));

    for (i = 0; i < height; i++)
        for (j = 0; j < width; j++)
            array[i][j] = ' ';

   checkarray = (int*) malloc(width * sizeof (int ));
    for (int k = 0; k < width; ++k) checkarray[k]=(int *)malloc(width * sizeof(checkarray));
    for (i=1; i<=width; i++)checkarray[i]=0;

    //MENU GIA AUTOMATO - MANUAL
    printf("\t|-----------------------------------|\n");
    printf("\t|    EPILOGH PARAMETROPOIHSHS       |\n");
    printf("\t|-----------------------------------|\n");
    printf("\t| (a) GIA AYTOMATH KATASKEYH PISTAS |\n");
    printf("\t|  (b) GIA MANUAL KATASKEYH PISTAS  |\n");
    printf("\t|-----------------------------------|\n");
    printf(" H EPILOGH SAS :  ");
    scanf("%c", &para);

    if (para == 'b') {bool Exit = true;//Manual Kataskeyi
        while(Exit)// Exodos An Epilogi ==0
        //Pernaei Meso Ths Function "MENU" thn epilogi tou xrhsth
        {epilogi=menu(epilogi); if(epilogi==0){Exit=false; printf("\n################ Bye Bye!!! #################\n");}
        else{designs(epilogi);}}}//Efoson Einai Manual i epilogi Mpainei sthn Function Design Gia na epilexoume sxedio
    if (para == 'a')//Automati Kataskeyi
    {////AYTH H KATASKEYH DOYLEYEI STA YPARXWN DEFINE, KATHE FORA VGAZEI DIAFORETIKOUS SYNDIASMOYS, ALLA EINAI MANUAL ENA 30% KYRIWS LOGO TWN EMPODIWN EDAFOYS////
        srand ( time(NULL) );
        int racount[6]={1,2,3,4,5,6 };
        int rcount[4]= {0,25,50,75};
        for ( i = 0 ; i < 6 ; i++ )
        {//Anakatevei olo ton pinaka se diaforetiki seifra kathe fora
            int r = rand() % 5 ; //Dialegei apo to 1 - 6 enan arithmo
            int temp = racount [ i ] ;
            racount [ i ] = racount [ r ] ;
            racount [ r ] = temp ;}
        for ( i = 0 ; i < 3 ; i++ )
        {//Anakatevei olo ton pinaka se diaforetiki seifra kathe fora
            int r1 = rand() % 4 ; //Dialegei apo to 1 - 4 enan arithmo
            int temp = rcount [ i ] ;
            rcount [ i ] = rcount [ r1 ] ;
            rcount [ r1 ] = temp ;}
        srand(time(NULL));
        for (i = 0; i <= 5; i++) {
            int thesi1 = rand() % 100 + 1;//Tyxaios arithmos 1-100 width
            thesi = rcount[i];
            epilogi=racount[i];
            if(epilogi ==1){ draw(epilogi,10,thesi,NULL); }
            if(epilogi ==2){ draw(epilogi,10, thesi,NULL);}
            if(epilogi ==3){ draw(epilogi, 6, thesi,NULL);}
            if(epilogi ==4){ draw(epilogi,6, thesi,NULL); }
            if(epilogi ==5){ draw(epilogi,5, thesi1, NULL);   }
            if(epilogi ==6){ draw(epilogi,14, thesi1, 28);    }
        }
        draw(epilogi=0);
    }
}

int menu(int choose) {// Function Menu gia epilogi Sxedioy
    printf("\t-----------------------------------------------------\n");
    printf("\t| PARAKALO EPILEXTE TO SXHMA POY THELETE NA FTIAXW: |\n"); //Epilogi Sxhmatos
    printf("\t|                                                   |");
    printf("\n\t| - (1)  SKALA\t\t\t\t\t     |\n"
           "\t| - (2)  KASTRO\t\t\t\t\t    |\n"
           "\t| - (3)  KATAPAKTH\t\t\t\t   |\n"
           "\t| - (4)  EMPODIA\t\t\t\t    |\n"
           "\t| - (5)  SYNNEFO\t\t\t\t    |\n"
           "\t| - (6)  TOYBLAKIA\t\t\t\t    |\n"
           "\t| - (0)  EXODOS APO TO PROGRAMMA\t\t    |\n");
    printf("\t|                                                   |\n");
    printf("\t-----------------------------------------------------\n");
    printf("Noumero Epilogis(0-6)  :  ");
    scanf("%d", &choose);
    return  choose;// Epistrefei Epilogi
}

void designs()//Auti i function paravlepetei otan theloume automati kataskeui
{// Otan einai manual Mpainei gia parametropoiisi sxediou
    int chk, chk1, i,sum = 0;
    bool Ok = true;

    printf("SYMVOULEYTEITE EDW...\n");
    for (i = 1; i <= width; i++) { printf("[%d:%d] ", i, checkarray[i]); }
    printf("\n");
    if (epilogi == 1)
    {
        while(Ok){///GIA OSO EXOYME LATHOS EPILOGI THESIS, EPANALYPSH.
            printf("\nH Epilogi Sas Einai H SKALA.\n");
            printf("Epilexte To Ypsos Tis Skalas:\n");                  //Epilogh Ypsous Skalas
            printf("YPSOS (6 - 18): ");
            scanf("%d", &y);                                            //Diavazei Ypsos Apo Xrhsth
            printf("Epilexte se pia Thesi Thelete na Mpei: ");
            scanf("%d", &thesi);
            ///---------------------------------------ELEGXOS----------------------------------////
            chk = thesi+((2 * y) + 3);
            for (i = thesi; i <= chk; i++)///APO THESI EPILOGIS MEXRI SHMEIO ~ ELEGXOU
                {if (checkarray[i] == 1) {sum = sum + 1; printf("THESH:[%d]KALYMENH    \n", i); break;}///O PINAKAS EINAI GEMATOS [0] AN SYNANTHSEI [1] BREAK SUM+1 KAI MNM ELEGXOU
                ///DIAFORETIKA SKANAREI OLO TON PINAKA KAI AN MEXRI TELOS DEN SYNANTHSOYME 0 GEMIZOYME TIS THESEIS TOY PINAKA ELEGXOU ME[1]
                 if (y < height & i <= chk && sum == 0) { for (i = thesi; i <= chk; i++){ checkarray[i] = 1; } Ok = false; draw(epilogi,y,thesi,M);}}
            }
    }
    if (epilogi == 2) {
        while(Ok)
        {
            printf("\nH epilogi Sas Einai To KASTRO.\n");                 // Kastro
            printf("Epilexte To Ypsos Toy Kastrou:\n");
            printf("YPSOS(5 - 30) : ");
            scanf("%d", &y);//Diavazei ypsos
            printf("Epilexte se pia Thesi Thelete na Mpei: ");
            ///---------------------------------------ELEGXOS----------------------------------////
            scanf("%d", &thesi);
            chk = thesi+(y + y + 3);
            for (i = thesi; i <= chk; i++) { if (checkarray[i] == 1) {sum = sum + 1; printf("THESH:[%d]KALYMENH    \n", i); break;}
                if (y + 2 < height & i <= chk && sum == 0) { for (i = thesi; i <= chk; i++){ checkarray[i] = 1; } draw(epilogi,y,thesi,M); }}Ok = false;}
    }
    if (epilogi == 3) {
        while(Ok==true){
            printf("\nH Epilogi Sas Einai i KATAPAKTH.\n ");              //Katapakti
            printf("Parakalw Epilexte To Ypsos Tis Katapaktis (3-8):\n");
            printf("YPSOS(5 - 20) :  ");
            scanf("%d", &y);
            printf("Epilexte se pia Thesi Thelete na Mpei: ");
            scanf("%d", &thesi);
            ///---------------------------------------ELEGXOS----------------------------------////
            chk = thesi+y;
            for (i = thesi; i <= chk; i++) { if (checkarray[i] == 1) {sum = sum + 1; printf("THESH:[%d]KALYMENH    \n", i); break;}
                if (y<height & i <= chk && sum == 0) { for (i = thesi; i <= chk; i++){ checkarray[i] = 1; } draw(epilogi,y,thesi,M); }}Ok = false;}
    }

    if (epilogi == 4) {
        while(Ok==true){
            printf("\nEpilexate TA EMPODIA.\n");                          //Empodia
            printf("Parakalw Epilexte To Megisto Ypsos Sta Empodia.\n");
            printf("YPSOS(Apo 2-10) :");
            scanf("%d", &y);
            printf("Epilexte se pia Thesi Thelete na Mpei: ");
            scanf("%d", &thesi);
            ///---------------------------------------ELEGXOS----------------------------------////
            y = thesi+((y * y) + y);
            for (i = thesi; i <= chk; i++)
            {
                if (checkarray[i] == 1) {sum = sum + 1; printf("THESH:[%d]KALYMENH    \n", i); break;}
                if (y<height & i <= chk && sum == 0) { for (i = thesi; i <= chk; i++){ checkarray[i] = 1; } Ok = false; draw(epilogi,y,thesi,M);}
            }}
            }
    if (epilogi == 5) {
        while(Ok==true){
            printf("\nEpilexate TO SYNNEFO.\n");
            printf("Epilexte Systoixia Twn Synnefwn.\n");               //Synnefo
            printf("Epitrepomeno Euros (3-12) : ");
            scanf("%d", &y);
            printf("Epilexte se pia Thesi Thelete na Mpei: ");
            scanf("%d", &thesi);
            ///---------------------------------------ELEGXOS----------------------------------////
            chk1 = thesi+(2 * y + 5);
            for (i = thesi; i <= chk1; i++)
            {
                if (checkarray[i] == 1) {sum = sum + 1; printf("THESH:[%d]KALYMENH    \n", i); break;}
                if (i <= chk1 && sum == 0) { for (i = thesi; i <= chk1; i++){ checkarray[i] = 1; } Ok = false; draw(epilogi,y,thesi,M);}
            }}
    }
    if (epilogi == 6) {
        while(Ok==true) {
            printf("\nEpilexate TA TOYBLAKIA.\n");                        //Touvlakia
            printf("Parakalw Epilexte To Ypsos Pou Tha Mpoun.\n");
            printf("YPSOS :");
            scanf("%d", &y);
            printf("Epilexte To Mikos Tis Mparas.\n");
            printf("MHKOS :");
            scanf("%d", &M);
            printf("Epilexte se pia Thesi Thelete na Mpei: ");
            scanf("%d", &thesi);
            ///---------------------------------------ELEGXOS----------------------------------////
            chk1 = thesi+M;
            for (i = thesi; i <= chk1; i++)
            {
                if (checkarray[i] == 1) {sum = sum + 1; printf("THESH:[%d]KALYMENH    \n", i); break;}
                if (i <= chk1 && sum == 0) { for (i = thesi; i <= chk1; i++){ checkarray[i] = 1; } Ok = false; draw(epilogi,y,thesi,M);}
            }}
    }
}
//EDW EINAI OLH H PARAMETROPOIHSH - SXEDIASH
void draw(int epilogi,int y,int thesi,int M)
{
    int i, j, grammi, stili, stars;
        printf("\n\n");
        if (epilogi == 0) {
            //Exit = false;
            printf("\n################ Bye Bye!!! #################\n");
        }
        if (epilogi == 1) {                             /////SKALA////
            grammi = height - 1;
            stars = y + 1;
            if (y >= 6 & y <= 25 & y < height)                         //Euros Timwn
            {
                //Apo Dexia Pros Aristera - Apo Katw Pros Ta Epanw//
                for (i = 0; i < 1; i++) {
                    stili = thesi + y;
                    for (j = 0; j < 3; j++) {
                        array[grammi][stili +
                                      7] = '*';             //Typwnei Vasi 3 Asteria Apo Kontari(Apo Aristera  Pros Dexia)
                        stili++;
                    }
                    for (j = 0; j < 1; j++) {
                        array[grammi - y - 2][stili + 5] = '*';         //Prwti seira kontari
                    }
                }
                for (i = 0; i < y; i++)                             //Dimiourgia Skalas
                {
                    stili = thesi;
                    for (j = 0; j < stars; j++) {
                        array[grammi][stili] = '*';
                        stili++;
                    }
                    stars--;
                    thesi++;
                    for (j = 0; j < 1; j++) {
                        array[grammi][stili + 7] = '*';             //Dimiourgia kontariou
                    }
                    grammi--;
                }
                stars = 3;
                for (i = 0; i < 2; i++)                              //Simaia 2 Grammes
                {
                    stili = thesi + 8;
                    for (j = 0; j < stars; j++) {
                        array[grammi - 1][stili] = '*';
                        stili--;
                    }
                    grammi++;
                    stars--;
                }
            } else {
                printf("### EKTOS ORIWN TOY PINAKA ###");
            }
        }
        if (epilogi == 2) {                                         ////KASTRO////
            grammi = height - 1;
            if (y >= 5 & y < 30 && y + 2 < height) {
                for (i = 0; i < 2; i++)                            //Porta - Ntoubaria
                {
                    stili = thesi;
                    for (j = 0; j < y; j++) {
                        array[grammi][stili] = '*';
                        stili++;
                    }
                    for (j = 0; j < y; j++) {
                        array[grammi][stili + 3] = '*';
                        stili++;
                    }
                    grammi--;
                }
                for (i = 0; i < y - 1; i++)                          //Mesaio Block
                {
                    stili = thesi;
                    for (j = 0; j < 2 * y + 3; j++) {
                        array[grammi][stili] = '*';
                        stili++;
                    }
                    grammi--;
                }
                for (i = 0; i < 1; i++)                             // Taratsa TouBlakia
                {
                    stili = thesi;
                    for (j = 0; j < y + 2; j++) {
                        array[grammi][stili] = '*';
                        stili = stili + 2;
                    }
                }
            } else {
                printf("### EKTOS ORIWN TOY PINAKA ###");
            }
        }
        if (epilogi == 3) {                                     ////KATAPAKTH////
            grammi = height - 1;
            if (y >= 5 & y <= 20 & y + 3 < height) {
                for (i = 0; i < 2; i++)                       //Panw Katw Grammi Vasis
                {
                    stili = thesi;
                    for (j = 0; j < y; j++) {
                        array[grammi][stili] = '*';
                        stili++;
                    }
                    grammi = grammi - y + 1;
                }
                grammi = height - 2;                         //Epanafora Grammis -2
                for (i = 0; i < y - 2; i++)                     //Mesaies Grammes Vasis
                {
                    stili = thesi;
                    for (j = 0; j < 2; j++) {
                        array[grammi][stili] = '*';
                        stili = stili + y - 1;                  //asteria
                    }
                    grammi--;                             //2 theseis i grammi
                }
                for (i = 0; i < 2; i++)                        //Platforma
                {
                    stili = thesi - 1;
                    for (j = 0; j < y + 2; j++) {
                        array[grammi - 1][stili] = '*';
                        stili++;
                    }
                    grammi--;
                }
            } else {
                printf("### EKTOS ORIWN TOY PINAKA ###");
            }
        }
        if (epilogi == 4) {                                     ////EMPODIA////
            grammi = height - 1;
            printf("\n\n");
            stars = y;
            if (y >= 2 & y <= 10 & y < height) {
                for (i = 0; i < y; i++)                           //Apo Mesi Kai Aristera Empodio
                {
                    stili = thesi + y * 2 + 3;
                    for (j = 0; j < stars; j++) {
                        array[grammi][stili] = '*';
                        stili = stili - 3;                       //2 Kena Kai Asteraki
                    }
                    stars--;
                    grammi--;
                }
                stars = y;                                     //Epanafora Asteriwn
                grammi = height - 1;                             //Epanafora Grammis Sti Vasi
                for (i = 0; i < y; i++)                           //Apo Mesi Kai Dexia Empodio
                {
                    stili = thesi + y * 2 + 6;
                    for (j = 0; j < stars; j++) {
                        array[grammi][stili] = '*';
                        stili = stili + 3;                       //2 Kena Kai Asteraki
                    }
                    stars--;
                    grammi--;
                }
            } else {
                printf("### EKTOS ORIWN TOY PINAKA ### ");
            }
        }                                                       ////SYNNEFO////
        if (epilogi == 5) {
            grammi = (height - 18);                            //To Ypsos Tou Synnefou Stin Pista
            printf("\n\n");
            if (y >= 3 & y <= 12 & thesi + y + y + 1 < width) {
                for (i = 1; i <= 4; i++) {                      //4 Seires to synnefo
                    stili = thesi;
                    if (i == 1) {
                        for (j = 1; j <= y; j++) {              //Parametropoihsh (Ektypwshs) 1hs grammhs
                            array[grammi][stili] = ' ';
                            stili++;
                            array[grammi][stili] = '*';
                            stili++;
                            array[grammi][stili] = '*';
                            stili++;
                        }
                    }
                    if (i == 4 & y % 2 == 0) {                  //Parametropoihsh (ektypwshs )4hs grammhs
                        for (j = 1; j <= (3 * y) / 2; j++) {
                            array[grammi][stili] = ' ';
                            stili++;
                            array[grammi][stili] = '*';
                            stili++;
                        }
                    } else if (i == 4 & y % 2 == 1) {
                        for (j = 0; j <= (3 * y) / 2; j++) {
                            array[grammi][stili] = ' ';
                            stili++;
                            array[grammi][stili] = '*';
                            stili++;
                        }
                    } else if (i == 2 || i == 3) {              //Parametropoihsh (ektypwshs) 2-3 grammhs
                        for (j = 0; j <= 3 * y; j++) {
                            array[grammi][stili] = '*';
                            stili++;
                        }
                    }
                    grammi++;
                }
            } else {
                printf("### EKTOS ORIWN TOY PINAKA ### ");
            }
        }
        if (epilogi == 6) {                                 /////TOYBLAKIA/////
            grammi = height - y;                            //To Ypsos Ton Touvlakiwn
            printf("\n\n");
            if (M + thesi < width & y < height) {
                for (i = 0; i < 1; i++)                        //Mia Grammi
                {
                    stili = thesi;
                    for (j = 0; j < M; j++)                    //"M" MHkos THs Mparas
                    {
                        array[grammi][stili] = '*';
                        stili++;
                    }
                }
            } else {
                printf("### EKTOS ORIWN TOY PINAKA ### ");
            }
        }
        else if (epilogi < 0 || epilogi > 6)
        { printf("############### LATHOS EPILOGH ##############");}
        print_array(array);
   // }
}
void print_array(char** array)
{
    int i,j;

    printf("\n |"); for(j=0; j<width; j++) printf("-");
    printf("|\n");
    for(i=0; i<height; i++)
    {
        printf("%d|", (height-1-i)%10);
        for(j=0; j<width; j++) printf("%c", array[i][j]);
        printf("|\n");
    }
    printf(" |"); for(j=0; j<width; j++) printf("-");
    printf("|");

    printf("\n  ");
    for(i=0; i<width; i++) printf("%d",i%10);
    printf("\n");
}

