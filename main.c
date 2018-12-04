/* 
 * File:   main.c
 * Author: Mariana Brito
 *
 * Created on 8 de Novembro de 2016, 15:00
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define QTD 10
int menu()
{
        
         int x;
        printf("\n ****ESTATISTICA CALCULATOR**** \n");
        
        printf(" \n 1-Media");
              
        printf(" \n 2-Moda");
                
        printf(" \n 3-Mediana");
                
        printf(" \n 4-Ponto Medio");
        
        printf(" \n 5-Media Ponderada");
        
        printf(" \n 6-Amplitude");
        
        printf(" \n 7-Desvio");
        
        printf(" \n 8-Desvio Medio ou absoluto");
        
        printf(" \n 9-Desvio Padrao");
        
        printf(" \n 10-Variancia");
        
         printf(" \n 11-Frequencia Acumulada");
         
        printf(" \n 12-Frequencia Relativa");
        
        printf(" \n 13-Histograma");
        
        printf(" \n 14-Quartis");
        
        printf(" \n 15-Quintis");
        
        printf(" \n 16-Decis");
        
        printf(" \n 17-Percentis");
        
        printf(" \n 18-Assimetria");
        
        printf(" \n 19-Curtose");

        printf(" \n 0-Sair");

        printf(" \n Opcao selecinada: ");
        scanf("%d",&x);
        
         if(x==1)
         {
            media();
        }
        else if(x==2)
        {
            moda();
        }
    else if(x==3)
    {
        mediana();
    }
        else if(x==4)
    {
        ptmedio();
    }
        else if(x==5)
    {
        medpond();
    }
        else if(x==6)
    {
        amplitude();
    }
         else if(x==7)
    {
        desvio();
    }
         else if(x==8)
    {
        dv_medio();
    }
         else if(x==9)
    {
        dv_padrao();
    }
         else if(x==10)
    {
        variancia();
    }
        else if(x==11)
    {
        f_acumulada();
    }
         else if(x==12)
    {
        f_relativa();
    }
        else if(x==13)
    {
        //histograma();
    }
         else if(x==14)
    {
        quartis();
    }
         else if(x==15)
    {
        quintis();
    }
         else if(x==16)
    {
        decis();
    }
         else if(x==17)
    {
        percentis();
    }
        else if(x==18)
    {
        assimetria();
    }
        else if(x==19)
    {
        curtose();
    }
    else
    {
            printf("Operacao Invalida! Tente Novamente!");
    }    
        return x;
}

int media()
{
    float n=0;
    int y,m;
    printf("______CALCULAR MEDIA_______");
    for(m=1;m<QTD;m++)
    {
        printf("\n Numero a tirar media:");
        scanf("%f",&y);
        n=n+y;
        printf("\n Deseja adicionar mais numero? \n 1 para nao \n Qualquer tecla para sim \n Opcao: ");
        scanf("%d",&y);
        if(y==1){break;}
    }

    int resultado=n/m;
    printf("\n \n **********RESULTADO********** \n");
    printf(" \n Media: %.2f \n ",resultado);
    return resultado;
}
void moda()
{
    int x[QTD],y[QTD],i,j,m,k,moda_ant,index=0,cont=0;
            printf("______CALCULAR MODA_______");
            for(m=0;m<QTD;m++)
            {
                printf("\n Numero componente do rol:");
                scanf("%d",&x[m]);
                printf("\n Deseja adicionar mais numero? \n 1 para NAO \n Qualquer tecla para SIM \n Opcao: ");
                scanf("%d",&j);
                y[m]=1;
                if(j==1){break;}
            }
            m=m+1;
            if(m==1){
                printf("Nao ha Moda!!!");
                return 0;
            }
            for(i=0;i<m;i++)
            {
               for(j=0;j<m;j++)
               {
                   if(x[i]==x[j] && i!=j)  
                   {
                        y[i]++;
                   }                 
               }
            } 
            for(j=0;j<m;j++)
               {
                   if(y[j]>index)  
                   {
                       index=y[j];
                   } 
               }
            if(index==1){printf("Nao ha moda!!!");
            return 0;}
            for(j=0;j<m;j++)
               {
                   if(y[j]==index)  
                   {
                       cont++;
                   }                 
               }
           
            cont=cont/index;
            
            if(cont==1)
            {
                printf("\n \n **********RESULTADO********** \n");
                for(j=0;j<m;j++)
                {
                    if(y[j]==index && index>1)
                    {   
                        printf("Moda aparece %d vezes \n",index);
                        printf("Modal: %d ",x[j]);
                        k++;
                    }
                    if(k==cont)return 0;
                }
            }
            else
            {
                if(cont==2)
                {
                   printf("\n \n **********RESULTADO********** \n");
                   printf("Moda aparece %d vezes\n ",index);
                   printf("Bimodal: ");
                   moda_ant=NULL;
                   for(j=0;j<m;j++)
                        {
                            if(y[j]==index && x[j]!=moda_ant && index>1)
                            {   
                                moda_ant=x[j];
                                printf("%d ",x[j]);
                                k++;
                            }
                            if(k==cont)return 0;
                        }
                }
                else
                {
                   printf("\n \n **********RESULTADO********** \n");
                        printf("Multimodal!");
                        return 0;
                    }
                }         
}
 
void mediana()
{
    int m,j,i;
    float mediana,k,aux, x[QTD];
    printf("\n ______CALCULAR MEDIANA_______\n \n");
    printf("Quantos elementos deseja inserir?");
    scanf("%d",&m);
    
     for( i=0; i<m; i++ ){
          printf("\nDigite um valor: ");
          scanf("%f",&x[i]);
          }
          for( i=0; i<m; i++ ){
                  for( j=i+1; j<m; j++ ){
                       if( x[i] > x[j] ){
                           aux = x[i];
                           x[i] = x[j];
                           x[j] = aux;
                       }
                  }
           }
           printf("\n Rol inserido: \n");
           for(i=0;i<m;i++)
           {
                            printf(" % .2f  ",x[i]);
           }     
    //TEM QUE ORDENAR ordem_funcion();
    mediana=m/2;
    if(m%2!=0)
    {
        m=mediana;
        printf("\n Mediana :%.0f \n",x[m]);
    }
    else
    {
        m=mediana-1;
        k=(x[m]+x[m+1])/2;
        printf("\n Mediana :%.2f \n",k);
    }
}

void ptmedio()
{
    int m,j;
    float x[QTD];
    float maior;
    float menor;
     printf("______CALCULAR PONTO MEDIO_______");
    for(m=0;m<QTD;m++)
    {
        printf("\n Numero componente do rol:");
        scanf("%f",&x[m]);
        printf("\n Deseja adicionar mais numero? \n 1 para NAO \n Qualquer tecla para SIM \n Opcao: ");
        scanf("%d",&j);
        if(j==1){break;}
    }
    m=m+1;
    maior=x[0];
    for(j=1;j<m;j++)
               {
                   if(x[j]>maior)  
                   {
                       maior=x[j];
                   } 
               }
    menor=maior;
    for(j=0;j<m;j++)
               {
                   if(x[j]<menor)  
                   {
                       menor=x[j];
                   } 
               }
    printf("\n Ponto mais alto:%.2f \n ",maior);
    printf("\n Ponto mais baixo:%.2f \n",menor);
    float pt=(maior+menor)/2;
    printf("\n Ponto Medio:%.2f \n",pt);
}

void medpond()
{
    int m,j;
    float x[QTD],y[QTD],n=0;
     printf("______CALCULAR MEDIA PONDERADA_______");
    for(m=0;m<QTD;m++)
    {
        printf("\n Numero componente do rol:");
        scanf("%f",&x[m]);
        printf("\n Peso:");
        scanf("%f",&y[m]);
        n=n+(x[m]*y[m]);
        printf("\n Deseja adicionar mais numero? \n 1 para NAO \n Qualquer tecla para SIM \n Opcao: ");
        scanf("%d",&j);
        if(j==1){break;}
    }
     printf("Média Ponderada:%.2f",(n/m));
}

void amplitude()
{
    int m,j;
    float x[QTD];
    float maior;
    float menor;
     printf("______CALCULAR PONTO MEDIO_______");
    for(m=0;m<QTD;m++)
    {
        printf("\n Numero componente do rol:");
        scanf("%f",&x[m]);
        printf("\n Deseja adicionar mais numero? \n 1 para NAO \n Qualquer tecla para SIM \n Opcao: ");
        scanf("%d",&j);
        if(j==1){break;}
    }
    m=m+1;
    maior=x[0];
    for(j=1;j<m;j++)
               {
                   if(x[j]>maior)  
                   {
                       maior=x[j];
                   } 
               }
    menor=maior;
    for(j=0;j<m;j++)
               {
                   if(x[j]<menor)  
                   {
                       menor=x[j];
                   } 
               }
    printf("\n Ponto mais alto:%.2f \n ",maior);
    printf("\n Ponto mais baixo:%.2f \n",menor);
    float amp=maior-menor;
    printf("Amplitude: %.2f",amp);
}

desvio()
{
    float x[QTD],media_desvio,dv,n=0;
    int m,j;
    printf("______CALCULAR DESVIO_______");
    for(m=0;m<QTD;m++)
    {
        printf("\n Numero a tirar o desvio:");
        scanf("%f",&x[m]);
        n=n+x[m];
        printf("\n Deseja adicionar mais numero? \n 1 para nao \n Qualquer tecla para sim \n Opcao: ");
        scanf("%d",&j);
        if(j==1){break;}
    }
    
    m=m+1;
    media_desvio=n/m;
    printf("Valores   |  Desvio \n ",media_desvio);
    for(j=0;j<m;j++)
    {
        dv=x[j]-media_desvio;
        if(dv<0) dv=dv*-1;
        printf(" %.2f       %.2f \n ",x[j],dv);
    }
}

dv_medio()
{
    float x[QTD],media_desvio,dv=0,n=0;
    int m,j;
    printf("______CALCULAR DESVIO MEDIO OU ABSOLUTO_______");
    for(m=0;m<QTD;m++)
    {
        printf("\n Numero a tirar o desvio:");
        scanf("%f",&x[m]);
        n=n+x[m];
        printf("\n Deseja adicionar mais numero? \n 1 para nao \n Qualquer tecla para sim \n Opcao: ");
        scanf("%d",&j);
        if(j==1){break;}
    }
    
    m=m+1;
    media_desvio=n/m;
    for(j=0;j<m;j++)
    {
        dv=dv+(x[j]-media_desvio);
        if(dv<0) dv=dv*-1;        
    }
    printf("Desvio Medio ou Absoluto: %.2f",dv);
}

dv_padrao()
{
    float x[QTD],media_desvio,dv=0,n=0;
    int m,j;
    printf("______CALCULAR DESVIO PADRAO_______");
    for(m=0;m<QTD;m++)
    {
        printf("\n Numero a tirar o desvio:");
        scanf("%f",&x[m]);
        n=n+x[m];
        printf("\n Deseja adicionar mais numero? \n 1 para nao \n Qualquer tecla para sim \n Opcao: ");
        scanf("%d",&j);
        if(j==1){break;}
    }
    
    media_desvio=n/m;
    for(j=0;j<m;j++)
    {
        dv=dv+pow((x[j]-media_desvio),2);
        if(dv<0) dv=dv*-1;        
    }
    dv=sqrt(dv)/m;
    printf("Desvio Padrao: %.2f",dv);
}

variancia()
{
     float x[QTD],media_desvio,dv=0,n=0;
    int m,j;
    printf("______CALCULAR  VARIANCIA_______");
    for(m=0;m<QTD;m++)
    {
        printf("\n Numero a tirar a variancia:");
        scanf("%f",&x[m]);
        n=n+x[m];
        printf("\n Deseja adicionar mais numero? \n 1 para nao \n Qualquer tecla para sim \n Opcao: ");
        scanf("%d",&j);
        if(j==1){break;}
    }
    
    media_desvio=n/m;
    for(j=0;j<m;j++)
    {
        dv=dv+pow((x[j]-media_desvio),2);
        if(dv<0) dv=dv*-1;        
    }
    dv=sqrt(dv)/m;
    dv=pow(dv,2);
    printf("Variancia: %.2f",dv);
}

f_acumulada()
{
    int m,j,y[QTD],f_ac[QTD];
    float x[QTD],n=0;
     printf("______CALCULAR FREQUENCIA_______");
    for(m=0;m<QTD;m++)
    {
        printf("\n Numero componente do rol:");
        scanf("%f",&x[m]);
        printf("\n Frequencia:");
        scanf("%d",&y[m]);
        printf("\n Deseja adicionar mais numero? \n 1 para NAO \n Qualquer tecla para SIM \n Opcao: ");
        scanf("%d",&j);
        if(j==1){break;}
    }
     m=m+1;
     printf("Valores   |  Frequencia    |   Frequencia Acumulada \n ");
     for(j=0;j<m;j++)
     {
         if(j==0)f_ac[j]=y[j];
         else
         {
             f_ac[j]=y[j]+f_ac[j-1];
         }
         printf("%.2f                %d                   %d \n",x[j],y[j],f_ac[j]);
     }
}

f_relativa()
{
     int m,j,y[QTD],i;
    float x[QTD],f_re[QTD];
     printf("______CALCULAR FREQUENCIA_______");
    for(m=0;m<QTD;m++)
    {
        printf("\n Numero componente do rol (sem repeticoes):");
        scanf("%f",&x[m]);
        printf("\n Frequencia:");
        scanf("%d",&y[m]);
        printf("\n Deseja adicionar mais numero? \n 1 para NAO \n Qualquer tecla para SIM \n Opcao: ");
        scanf("%d",&j);
        if(j==1){break;}
    }
    m=m+1;
         
     printf("Valores   |    Frequencia     |    Frequencia Relativa \n");
     for(j=0;j<m;j++)
     {
         if(j==0)f_re[j]=y[j]/m;
         else
         {
             f_re[j]=(y[j]+f_re[j-1])/m;
         }
          printf("%.2f               %d                 %.2f                    \n",x[j],y[j],f_re[j]);
     }
}

histograma()
{

}

quartis()
{
    int m,j,i,d=0,k,i_ant=0;
    float x[QTD];
     printf("______CALCULAR QUARTIS_______");
    for(m=0;m<QTD;m++)
    {
        printf("\n Numero componente do rol:");
        scanf("%f",&x[m]);
        printf("\n Deseja adicionar mais numero? \n 1 para NAO \n Qualquer tecla para SIM \n Opcao: ");
        scanf("%d",&j);
        if(j==1){break;}
    }
    m=m+1;
    for(k=1;k<=4;k++){
        d=d+25;
        printf("Q%d:",d);
        i=(d*m)/100;
        for(j=i_ant;j<i;j++)
        {
            printf("%.2f ",x[j]);
        }
        printf("\n");
         i_ant=i;
    }    
}
quintis()
{
    int m,j,i,d=0,k,i_ant=0;
    float x[QTD];
     printf("______CALCULAR QUINTIS_______");
    for(m=0;m<QTD;m++)
    {
        printf("\n Numero componente do rol:");
        scanf("%f",&x[m]);
        printf("\n Deseja adicionar mais numero? \n 1 para NAO \n Qualquer tecla para SIM \n Opcao: ");
        scanf("%d",&j);
        if(j==1){break;}
    }
    m=m+1;
    for(k=1;k<=5;k++){
        d=d+20;
        printf("Q%d:",d);
        i=(d*m)/100;
        for(j=i_ant;j<i;j++)
        {
            printf("%.2f ",x[j]);
        }
        printf("\n");
         i_ant=i;
    }    
}

decis()
{
    int m,j,i,d=0,k,i_ant=0;
    float x[QTD];
     printf("______CALCULAR DECIS_______");
    for(m=0;m<QTD;m++)
    {
        printf("\n Numero componente do rol:");
        scanf("%f",&x[m]);
        printf("\n Deseja adicionar mais numero? \n 1 para NAO \n Qualquer tecla para SIM \n Opcao: ");
        scanf("%d",&j);
        if(j==1){break;}
    }
    m=m+1;
    for(k=1;k<=10;k++){
        d=d+10;
        printf("Q%d:",d);
        i=(d*m)/100;
        for(j=i_ant;j<i;j++)
        {
            printf("%.2f ",x[j]);
        }
        printf("\n");
         i_ant=i;
    }    
}

percentis()
{
    int m,j,i,d=0,k,i_ant=0;
    float x[QTD];
     printf("______CALCULAR QUARTIS_______");
    for(m=0;m<QTD;m++)
    {
        printf("\n Numero componente do rol:");
        scanf("%f",&x[m]);
        printf("\n Deseja adicionar mais numero? \n 1 para NAO \n Qualquer tecla para SIM \n Opcao: ");
        scanf("%d",&j);
        if(j==1){break;}
    }
    m=m+1;
    for(k=1;k<=100;k++){
        d=d+1;
        printf("Q%d:",d);
        i=(d*m)/100;
        for(j=i_ant;j<i;j++)
        {
            printf("%.2f ",x[j]);
        }
        printf("\n");
         i_ant=i;
    }    
}

assimetria()
{
    int m,j,y[QTD],qtd=0,index;
    float x[QTD],n=0,_x,mo,dv,ass;
     printf("______CALCULAR ASSIMETRIA_______");
    for(m=0;m<QTD;m++)
    {
        printf("\n Numero componente do rol:");
        scanf("%f",&x[m]);
        printf("\n Frequencia:");
        scanf("%d",&y[m]);
        n=n+(x[m]*y[m]);
        qtd=qtd+y[m];
        printf("\n Deseja adicionar mais numero? \n 1 para NAO \n Qualquer tecla para SIM \n Opcao: ");
        scanf("%d",&j);
        if(j==1){break;}
    }
    _x=n/qtd;
    printf("Media:%.2f",_x);
    
    
    for(j=0;j<m;j++)
    {
        if(y[j]>index)  
        {
            index=y[j];
        } 
    }
            if(index==1){printf("Nao ha moda!!!");
            return 0;}
            for(j=0;j<m;j++)
               {
                   if(y[j]==index)  
                   {
                       mo=x[j];
                   }                 
               }
    printf("Moda:%.2f",mo);       
     
    
    for(j=0;j<m;j++)
    {
        dv=dv+pow((x[j]-_x),2);
        if(dv<0) dv=dv*-1;        
    }
    dv=sqrt(dv)/m;
    printf("Desvio Padrao: %.2f",dv);
    ass=(_x-mo)/dv;
    if(ass==0)
        printf("Distribuição é Simétrica!");
    if(ass>0)
        printf("Distribuição é Assimétrica Positiva!");
    if(ass<0)
        printf("Distribuição é Assimétrica negativa!");
    printf("Assimetria: %.2f",ass);
}

curtose()
{   int m,j,i,d=0,k,i_ant=0;
    float x[QTD],separatrizes[4],curtose;
     printf("______CALCULAR CURTOSE_______");
    for(m=0;m<QTD;m++)
    {
        printf("\n Numero componente do rol:");
        scanf("%f",&x[m]);
        printf("\n Deseja adicionar mais numero? \n 1 para NAO \n Qualquer tecla para SIM \n Opcao: ");
        scanf("%d",&j);
        if(j==1){break;}
    }
    m=m+1;
        d=25;
        printf("Q%d:",d);
        i=(d*m)/100;
        printf("%.2f ",x[i-1]);
        separatrizes[0]=x[i-1];
        printf("\n");
         i_ant=i;
         
        d=75;
        printf("Q%d:",d);
        i=(d*m)/100;
        printf("%.2f ",x[i-1]);
        separatrizes[1]=x[i-1];
        printf("\n");
         i_ant=i;
         
        d=90;
        printf("Q%d:",d);
        i=(d*m)/100;
        printf("%.2f ",x[i-1]);
        separatrizes[2]=x[i-1];
        printf("\n");
         i_ant=i;
         
        d=10;
        printf("Q%d:",d);
        i=(d*m)/100;
        printf("%.2f ",x[i-1]);
        separatrizes[3]=x[i-1];
        printf("\n");
         i_ant=i;
         
         curtose=(separatrizes[1]-separatrizes[0])/2*(separatrizes[3]-separatrizes[2]);
         if(curtose==0.263)
              printf("Curtose Mesocurtica!");
         if(curtose<0.263)
              printf("Curtose Leptocurtica!");
         if(curtose>0.263)
              printf("Curtose Platicurtica");
         printf("Curtose: %.3f ",curtose);
}
int main(int argc, char** argv) {
    int x=1;
    while(x!=0)
        x=menu();
    printf("Programa Encerrado! \n");
        
      
    return (EXIT_SUCCESS);
}

