/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<assert.h>


char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n) {
    //kth word ,mth sent, nth para
    char* rtnPtr;
    char* passDoc = document;
    char *paraPtr[5];
    char *sentPtr[m];
    char *wordPtr[k];
    //Dividing in Paragraphs
    char * paratoken = strtok(passDoc, "\n");
    while(paratoken != NULL){
      static int cnt = 0;
      paraPtr[cnt] = paratoken;
      
      if(cnt == (n - 1))
      {
          //printf("%s\n", paraPtr[cnt]);
          break;}
       cnt+=1;
      paratoken = strtok(NULL,"\n");
    }// converted in paras
    
    //sent nth paras to sentences
    char* sentToken = strtok(paraPtr[n-1], ".");
    while(sentToken != NULL){
       static int cnt = 0;
       sentPtr[cnt] = sentToken;
       if(cnt == (m - 1))
      {
          //printf("%s\n", sentPtr[cnt]);
          break;}
       cnt += 1;
       sentToken = strtok(NULL, ".");
    }
    
    //printf("%s\n", sentPtr[m - 1]);
    char* wordToken = strtok(sentPtr[m - 1], " ");
    while(wordToken != NULL)
    {
       static int cnt = 0;
       wordPtr[cnt] = wordToken;
       if(cnt == (k - 1))
      {
          rtnPtr = wordPtr[cnt];
          //printf("%s\n", wordPtr[cnt]);
          break;}
      cnt +=1;
      wordToken = strtok(NULL, " ");
    }
    return rtnPtr;
    
}

int main()
{
    char ****doc = 0;
    char ***para= 0;
    char **sent = 0;
    char *word = 0;
    char *test = (char*)malloc(sizeof(char) * 1024); 
    char str[] = "this is para1 sent 1. para1 sent2 let music plays great.\nThis is para2 sent1. para2 sent2 Dil kya karya";
    memcpy(test, str, strlen(str));
    
    doc = test;
    //printf("%s\n\n", doc);
   word =  kth_word_in_mth_sentence_of_nth_paragraph(doc, 3, 2, 1 );
    
    // word = doc;
     printf("%s", word);
    

    return 0;
}
