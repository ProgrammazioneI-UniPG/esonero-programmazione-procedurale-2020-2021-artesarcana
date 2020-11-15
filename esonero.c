#include <stdio.h> //inclusa per standard input output
#include <stdlib.h> //inclusa per l'utilizzo di rand() e srand()
#include <time.h> //inclusa per l'utilizzo di time()
#include <string.h> //inclusa per verificare la lunghezza di una stringa con strlen()

int main() {
  time_t t;
  srand ((unsigned) time(&t)); //inizializzazione del generatore di numeri casuali con seed tempo attuale
  const int array_ln = 128; //Costante di lunghezza massima degli array
  int array_ln_inserito; //Variabile con lunghezza del plaintext inserito
  char plaintext_array[array_ln]; //Testo in chiaro
  char cyphertext_array[array_ln]; //Testo cifrato
  int user_choice = 0; //scelta dello switch
  char key[array_ln]; //Chiave scelta dall'utente (Caso 1)
  char random_key[array_ln]; //Chiave randomica (Caso 2)

  //Inizio del software, richiesta del plaintext
  printf("Inserire una stringa di massimo 128 caratteri\n");
  fgets (plaintext_array, array_ln, stdin);
  array_ln_inserito = strlen(plaintext_array); //Controllo lunghezza plaintext
  printf("Digitare 1 per inserire una chiave con cui cifrare il testo in chiaro. Digitare 2 per generare una chiave casuale con cui cifrare il testo in chiaro\n");
  scanf("%d", &user_choice);
  switch (user_choice) //Scelta dell'utente se:
  {
    case 1: //inserimento chiave da parte dell'utente
          printf("Inserire una chiave di crifratura di lunghezza uguale o superiore al testo in chiaro\n");
          while(getchar()!='\n'); //Pulizia dello stream
          fgets(key,array_ln,stdin);
          for (int I=0; I < array_ln_inserito; I++)
            cyphertext_array[I] = plaintext_array[I] ^ key[I];
          printf("Stampa del cyphertext\n");
          printf("%s\n", cyphertext_array);
          printf("Stampa inversa\n");
          for (int I=0; I<array_ln_inserito; I++)
            plaintext_array[I]=cyphertext_array[I] ^ key[I];
          printf("%s\n", plaintext_array);
          break;
    case 2: //generazione di chiave casuale
          printf("Generazione di una chiave casuale\n");
          printf("La chiave è:\n");
          for (int I=0; I<array_ln_inserito; I++)
          {
            random_key[I]=(rand() % 128);
            printf("%c", random_key[I]);
          }
          printf("\n");
          for (int I=0; I<array_ln_inserito; I++)
            cyphertext_array[I]=plaintext_array[I] ^ random_key[I];
          printf("Stampa del cyphertext\n");
          printf("%s\n", cyphertext_array);
          printf("Stampa inversa\n");
          for (int I=0; I<array_ln_inserito; I++)
            plaintext_array[I]=cyphertext_array[I] ^ random_key[I];
          printf("%s\n", plaintext_array);
          break;
    default:
          printf("ATTENZIONE: Richiesta non valida. Digitare 1 o 2\n");
          break;
  }
  return 0;
}
