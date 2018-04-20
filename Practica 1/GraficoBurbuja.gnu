set terminal png

set output "burbuja.png"

set title "Análisis empirico de la complejidad temporal del algoritmo Burbuja."
set xlabel "talla"
set ylabel "tiempo(seg)"


y(x)=a+b*x+c*x*x
titulo="Ajuste: an2+bn+c"
fit y(x) "tablatiempos" using 1:2 via a,b,c


plot "tablatiempos" using 1:2 with lines title "Coste temporal",y(x) title titulo
