#include <math.h>

struct route
{
  char start[50];
  int length,uphill,downhill,maxaltitude,minaltitude;
  char finish[50];
};

void descendingAssortment(struct route A[],int N)
{
  char tempstart[50],tempfinish[50];
  int i=0,j=0,templength,tempuphill,tempdownhill,tempmaxaltitude,tempminaltitude;
  while (i<N)
  {
    j=i+1;
    while (j<N)
    {
      if (A[i].length<A[j].length)
      {
        templength=A[i].length;
        A[i].length=A[j].length;
        A[j].length=templength;
        tempuphill=A[i].uphill;
        A[i].uphill=A[j].uphill;
        A[j].uphill=tempuphill;
        tempdownhill=A[i].downhill;
        A[i].downhill=A[j].downhill;
        A[j].downhill=tempdownhill;
        tempmaxaltitude=A[i].maxaltitude;
        A[i].maxaltitude=A[j].maxaltitude;
        A[j].maxaltitude=tempmaxaltitude;
        tempminaltitude=A[i].minaltitude;
        A[i].minaltitude=A[j].minaltitude;
        A[j].minaltitude=tempminaltitude;
        strcpy(tempstart,A[i].start);
        strcpy(A[i].start,A[j].start);
        strcpy(A[j].start,tempstart);
        strcpy(tempfinish,A[i].finish);
        strcpy(A[i].finish,A[j].finish);
        strcpy(A[j].finish,tempfinish);
      }
      j++;
    }
    i++;
  }
}

void printDataFromStartToFinish(struct route A[],int N,int i)
{
  int estimatedtime;
  printf("From %s ",A[i].start);
  printf("to %s",A[i].finish);
  printf("\n");
  printf("Uphill %d, ",A[i].uphill);
  printf("Downhill %d",A[i].downhill);
  printf("\n");
  printf("Max altitude %d, ",A[i].maxaltitude);
  printf("Min altitude %d",A[i].minaltitude);
  printf("\n");
  printf("Length %d, ",A[i].length);
  estimatedtime=round(A[i].length/65.0+A[i].uphill/10.0);
  printf("Estimated time %d min",estimatedtime);
  printf("\n");
  printf("\n");
}

void printDataFromFinishToStart(struct route A[],int N,int i)
{
  int estimatedtime;
  printf("From %s ",A[i].finish);
  printf("to %s",A[i].start);
  printf("\n");
  printf("Uphill %d, ",A[i].downhill);
  printf("Downhill %d",A[i].uphill);
  printf("\n");
  printf("Max altitude %d, ",A[i].maxaltitude);
  printf("Min altitude %d",A[i].minaltitude);
  printf("\n");
  printf("Length %d, ",A[i].length);
  estimatedtime=round(A[i].length/65.0+A[i].downhill/10.0);
  printf("Estimated time %d min",estimatedtime);
  printf("\n");
  printf("\n");
}

void printDataFromStartToFinishFromRealTime(struct route A[],int N,int i,int T)
{
  int estimatedtime;
  float realtime;
  realtime=A[i].length/65.0+A[i].uphill/10.0;
  if (realtime<=T)
  {
    printf("From %s ",A[i].start);
    printf("to %s",A[i].finish);
    printf("\n");
    printf("Uphill %d, ",A[i].uphill);
    printf("Downhill %d",A[i].downhill);
    printf("\n");
    printf("Max altitude %d, ",A[i].maxaltitude);
    printf("Min altitude %d",A[i].minaltitude);
    printf("\n");
    printf("Length %d, ",A[i].length);
    estimatedtime=round(A[i].length/65.0+A[i].uphill/10.0);
    printf("Estimated time %d min",estimatedtime);
    printf("\n");
    printf("\n");
  }
}

void printDataFromFinishToStartFromRealTime(struct route A[],int N,int i,int T)
{
  int estimatedtime;
  float realtime;
  realtime=A[i].length/65.0+A[i].downhill/10.0;
  if (realtime<=T)
  {
    printf("From %s ",A[i].finish);
    printf("to %s",A[i].start);
    printf("\n");
    printf("Uphill %d, ",A[i].downhill);
    printf("Downhill %d",A[i].uphill);
    printf("\n");
    printf("Max altitude %d, ",A[i].maxaltitude);
    printf("Min altitude %d",A[i].minaltitude);
    printf("\n");
    printf("Length %d, ",A[i].length);
    estimatedtime=round(A[i].length/65.0+A[i].downhill/10.0);
    printf("Estimated time %d min",estimatedtime);
    printf("\n");
    printf("\n");
  }
}

void fPrintDataFromStartToFinish(struct route A[],int N,int i,FILE *file)
{
  int estimatedtime;
  fprintf(file,"From %s ",A[i].start);
  fprintf(file,"to %s",A[i].finish);
  fprintf(file,"\n");
  fprintf(file,"Uphill %d, ",A[i].uphill);
  fprintf(file,"Downhill %d",A[i].downhill);
  fprintf(file,"\n");
  fprintf(file,"Max altitude %d, ",A[i].maxaltitude);
  fprintf(file,"Min altitude %d",A[i].minaltitude);
  fprintf(file,"\n");
  fprintf(file,"Length %d, ",A[i].length);
  estimatedtime=round(A[i].length/65.0+A[i].uphill/10.0);
  fprintf(file,"Estimated time %d min",estimatedtime);
  fprintf(file,"\n");
  fprintf(file,"\n");
}

void fPrintDataFromFinishToStart(struct route A[],int N,int i,FILE *file)
{
  int estimatedtime;
  fprintf(file,"From %s ",A[i].finish);
  fprintf(file,"to %s",A[i].start);
  fprintf(file,"\n");
  fprintf(file,"Uphill %d, ",A[i].downhill);
  fprintf(file,"Downhill %d",A[i].uphill);
  fprintf(file,"\n");
  fprintf(file,"Max altitude %d, ",A[i].maxaltitude);
  fprintf(file,"Min altitude %d",A[i].minaltitude);
  fprintf(file,"\n");
  fprintf(file,"Length %d, ",A[i].length);
  estimatedtime=round(A[i].length/65.0+A[i].downhill/10.0);
  fprintf(file,"Estimated time %d min",estimatedtime);
  fprintf(file,"\n");
  fprintf(file,"\n");
}

struct route *readFromInput(int *n)
{
  struct route *A;
  int i=0;
  scanf("%d ",n);
  A=malloc((*n)*sizeof(struct route));
  while (i<*n)
  {
    fgets(A[i].start,50,stdin);
    A[i].start[strcspn(A[i].start,"\n")]='\0';
    scanf("%d %d %d %d %d ",&A[i].length,&A[i].uphill,&A[i].downhill,&A[i].maxaltitude,&A[i].minaltitude);
    fgets(A[i].finish,50,stdin);
    A[i].finish[strcspn(A[i].finish,"\n")]='\0';
    i++;
  }
  return A;
}

void printData(struct route A[],int N)
{
  int i=0;
  descendingAssortment(A,N);
  while (i<N)
  {
    if (strcmp(A[i].start,A[i].finish)==0)
    {
      printDataFromStartToFinish(A,N,i);
    }
    else
    {
      printDataFromStartToFinish(A,N,i);
      printDataFromFinishToStart(A,N,i);
    }
    i++;
  }
}

void findShort(struct route A[],int N)
{
  int L,i=0;
  scanf("%d",&L);
  descendingAssortment(A,N);
  while (i<N)
  {
    if (A[i].length<=L)
    {
      if (strcmp(A[i].start,A[i].finish)==0)
      {
        printDataFromStartToFinish(A,N,i);
      }
      else
      {
        printDataFromStartToFinish(A,N,i);
        printDataFromFinishToStart(A,N,i);
      }
    }
    i++;
  }
}

void findLocation(struct route A[],int N)
{
  int i=0;
  char location[50];
  fgets(location,50,stdin);
  location[strcspn(location,"\n")]='\0';
  descendingAssortment(A,N);
  while (i<N)
  {
    if (strcmp(location,A[i].start)==0)
    {
      printDataFromStartToFinish(A,N,i);
    }
    else if (strcmp(location,A[i].finish)==0)
    {
      printDataFromFinishToStart(A,N,i);
    }
    i++;
  }
}

void findUpHill(struct route A[],int N)
{
  int i=0;
  descendingAssortment(A,N);
  while (i<N)
  {
    if (A[i].uphill>A[i].downhill)
    {
      printDataFromStartToFinish(A,N,i);
    }
    else if (A[i].uphill<A[i].downhill)
    {
      printDataFromFinishToStart(A,N,i);
    }
    i++;
  }
}

void findDownHill(struct route A[],int N)
{
  int i=0;
  descendingAssortment(A,N);
  while (i<N)
  {
    if (A[i].uphill>A[i].downhill)
    {
      printDataFromFinishToStart(A,N,i);
    }
    else if (A[i].uphill<A[i].downhill)
    {
      printDataFromStartToFinish(A,N,i);
    }
    i++;
  }
}

void findAltitude(struct route A[],int N)
{
  int min,max,i=0;
  scanf("%d",&min);
  scanf("%d",&max);
  descendingAssortment(A,N);
  while (i<N)
  {
    if (A[i].minaltitude>=min && A[i].maxaltitude<=max)
    {
      if (strcmp(A[i].start,A[i].finish)==0)
      {
        printDataFromStartToFinish(A,N,i);
      }
      else
      {
        printDataFromStartToFinish(A,N,i);
        printDataFromFinishToStart(A,N,i);
      }
    }
    i++;
  }
}

void findTimely(struct route A[],int N)
{
  int T,i=0;
  scanf("%d",&T);
  descendingAssortment(A,N);
  while (i<N)
  {
    if (strcmp(A[i].start,A[i].finish)==0)
    {
      printDataFromStartToFinishFromRealTime(A,N,i,T);
    }
    else
    {
      printDataFromStartToFinishFromRealTime(A,N,i,T);
      printDataFromFinishToStartFromRealTime(A,N,i,T);
    }
    i++;
  }
}

struct route *readFromFile(int *n)
{
  FILE *file;
  struct route *A;
  int i=0;
  char S[50];
  scanf("%s ",S);
  A=malloc((*n)*sizeof(struct route));
  file=fopen(S,"r");
  if (file!=NULL)
  {
    fscanf(file,"%d ",n);
    while (i<*n)
    {
      fgets(A[i].start,50,file);
      A[i].start[strcspn(A[i].start,"\n")]='\0';
      fscanf(file,"%d %d %d %d %d ",&A[i].length,&A[i].uphill,&A[i].downhill,&A[i].maxaltitude,&A[i].minaltitude);
      fgets(A[i].finish,50,file);
      A[i].finish[strcspn(A[i].finish,"\n")]='\0';
      i++;
    }
    fclose(file);
  }
  return A;
}

void saveData(struct route A[],int N)
{
  FILE *file;
  int i=0;
  char S[50];
  scanf("%s ",S);
  file=fopen(S,"w");
  if (file!=NULL)
  {
    descendingAssortment(A,N);
    while (i<N)
    {
      if (strcmp(A[i].start,A[i].finish)==0)
      {
        fPrintDataFromStartToFinish(A,N,i,file);
      }
      else
      {
        fPrintDataFromStartToFinish(A,N,i,file);
        fPrintDataFromFinishToStart(A,N,i,file);
      }
      i++;
    }
    fclose(file);
  }
}