#include <stdio.h>
 
 double calcularDuracao (double hInicial, double mInicial, double hFinal, double mFinal) {
     
     mInicial = mInicial + (hInicial * 60);
     mFinal = mFinal + (hFinal * 60);
     
     double resultado = (mFinal - mInicial)/60;
     return resultado;
 }
 
int main() {
 
    int horaInicial, minutoInicial, horaFinal, minutoFinal;
    
    
    scanf("%i", &horaInicial);
    scanf("%i", &minutoInicial);
    scanf("%i", &horaFinal);
    scanf("%i", &minutoFinal);
     
    double duracao = calcularDuracao(horaInicial, minutoInicial, horaFinal, minutoFinal);
    int duracaoHora = duracao;
    int duracaoMinuto = (duracao - duracaoHora) * 60;
    
    printf("%i\n", duracaoHora);
    printf("%i", duracaoMinuto);
    
    return 0;
}