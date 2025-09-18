#include <stdio.h>
 
 double calcularDuracao (double hInicial, double mInicial, double hFinal, double mFinal) {
     
     mInicial = mInicial + (hInicial * 60);
     mFinal = mFinal + (hFinal * 60);
     
     double resultado = (mFinal - mInicial)/60;

     if ( resultado <= 0) {

        resultado = 24 + resultado;
        return resultado;

     }else{
        return resultado;
     }
     
 }
 
 void imprimir (int dHora, double dMinuto) {
     
     printf("O JOGO DUROU %i HORA(S) E %.lf MINUTO(S)\n", dHora, dMinuto);
 }
 
int main() {
 
    int horaInicial, minutoInicial, horaFinal, minutoFinal;
    
    scanf("%i", &horaInicial);
    scanf("%i", &minutoInicial);

    scanf("%i", &horaFinal);
    scanf("%i", &minutoFinal);    
     
    double duracao = calcularDuracao(horaInicial, minutoInicial, horaFinal, minutoFinal);
    int duracaoHora = duracao;
    double duracaoMinuto = (duracao - duracaoHora) * 60;
    
    imprimir(duracaoHora, duracaoMinuto);
    
    return 0;
}