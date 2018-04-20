set terminal png

set output "quickshort.png"

set title "Análisis empirico de la complejidad temporal del algoritmo Quickshort."
set xlabel "talla"
set ylabel "tiempo medio(seg)"


y(x)=a*x*log(x)+b*x+c
titulo="Ajuste"
fit y(x) "tablatiempos" using 1:2 via a,b,c


plot "tablatiempos" using 1:2 with lines title "Coste temporal",y(x) title titulo
