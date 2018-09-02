#include <stdio.h>
#include <math.h>
double f(double x){
    return sqrt(1.0-x*x);
}

int main(){
    printf("<====[問題]√1-x^2をx=0から1の範囲で積分する計算の近似解====>\n");
    int n, j;
    double a = 0.0, b = 1.0, h;
    double daikei1 = 0.0, daikei, simpson1 = 0.0, simpson2 = 0.0, simpson;
    double kaiseki_kai, d_gosa, s_gosa;
    do{
    printf("積分範囲の分割数n(偶数)を入力>> ");
    scanf("%d", &n);
    }while(n % 2 == 1);
    h = (b - a)/n;
    
    //台形公式
    for(j = 1; j <= n-1; j++){
        daikei1 += f(a + j * h);
    }
    daikei = h * (0.5 * f(a) + daikei1 + 0.5 * f(b));
    //シンプソンの公式
    for(j = 1; j <= n/2; j++){
        simpson1 += f(a + (2 * j - 1) * h);
    }
    for(j = 1; j <= n/2-1; j++){
        simpson2 += f(a + 2 * j * h);
    }
    simpson = h/3 * (f(a) + 4 * simpson1 + 2 * simpson2 + f(b));
    
    //相対誤差
    kaiseki_kai = M_PI/4;
    d_gosa = 100 * (daikei - kaiseki_kai)/kaiseki_kai;
    s_gosa = 100 * (simpson - kaiseki_kai)/kaiseki_kai;
    printf("<==計算結果==>\n");
    printf("台形公式の結果: %lf  相対誤差(%%): %5.3e\n", daikei, d_gosa);
    printf("シンプソンの公式の結果: %lf  相対誤差(%%): %5.3e\n", simpson, s_gosa);
    return 0;
}