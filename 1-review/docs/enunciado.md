# Lab 1 - C Programming Exercises

## 01-) Trip Calculator

Escreva um programa em C que receba os dados de consumo médio (km/l), tempo gasto numa
viagem (hora) e a velocidade média (km/h) de um automóvel, e calcule a distância percorrida
(km) e a quantidade de combustível (litros) utilizada pelo automóvel. Os dados devem ser
passados ao programa na forma de argumentos no momento da execução. Não deve ser utilizada
a função scanf ou similares. Ao final, o programa deve exibir os resultados na tela.




## 02-) Text Case Converter

Escreva um programa que receba uma linha de texto e a armazene em um array do tipo char
com, no máximo, 100 elementos. O programa deve transformar todas as letras da linha de
texto em letras maiúsculas e exibi-las na tela. Depois, deve transformar todas as letras da
linha de texto em letras minúsculas e, também, exibi-las na tela. Utilize as funções tolower e toupper, definidas na biblioteca ctype.h.




## 03-) Sales Commission Calculator

Uma empresa realiza o pagamento de seus vendedores através de comissões por suas vendas
semanais. Cada vendedor recebe R$ 500,00 por semana mais 9% do valor de suas vendas
naquela semana. Por exemplo, se um vendedor faturou R$ 5000,00 em vendas em uma semana,
seu pagamento será R$ 500,00 + 9% de R$ 5000,00, o que equivale a R$ 950,00. Escreva um
programa em C que determine quantos vendedores receberam salários em cada uma das faixas
a seguir:
a) R$ 500,00 a R$ 599,00
b) R$ 600,00 a R$ 699,00
c) R$ 700,00 a R$ 799,00
d) R$ 800,00 a R$ 899,00
e) R$ 900,00 a R$ 999,00
f) R$ 1000,00 a R$ 1199,00
g) R$ 1200,00 a R$ 1299,00
h) R$ 1300,00 ou mais

Para tanto, crie o tipo de dados Vendedor, utilizando struct e typedef. Este tipo de dados deve conter os campos nome e faturamento. Suponha que a empresa possui, pelo menos, 20 vendedores. Crie variáveis do tipo Vendedor para representar cada um dos vendedores e armazene-as em um array (do tipo Vendedor[]). Crie um segundo array (por exemplo, int
faixas[]) em que cada elemento represente uma das faixas salariais apresentadas acima. Ao final do processamento, o programa deve apresentar na tela as faixas salariais e o número de vendedores presentes em cada faixa.



## 04-) Data Analysis and Histogram

**Description:**
Considere o seguinte conjunto de dados:
```c
[6, 7, 8, 9, 8, 7, 8, 9, 8, 9, 7, 8, 9, 5, 9, 8, 7, 8, 7, 8, 6, 7, 8, 9, 3, 9, 8, 7, 8, 7, 7, 8, 9, 8, 9, 8, 9, 7, 8, 9, 6, 7, 8, 7, 8, 7, 9, 8, 9, 2, 7, 8, 9, 8, 9, 8, 9, 7, 5, 3, 5, 6, 7, 2, 5, 3, 9, 4, 6, 4, 7, 8, 9, 6, 8, 7, 8, 9, 7, 8, 7, 4, 4, 2, 5, 3, 8, 7, 5, 6, 4, 5, 6, 1, 6, 5, 7, 8, 7]
```
Escreva um programa que calcule e apresente na tela a média deste conjunto de dados. O
programa deve, também, apresentar na tela um histograma com as frequências de cada um dos
números deste conjunto de dados.


## Exercise 5: Employee Payroll Processor

 Escreva um programa que faça o processamento da folha de pagamentos dos funcionários de
uma empresa. Para tanto, crie um novo tipo de dados (utilizando typedef e struct), denominado Employee. Este novo tipo de dados deve conter os seguintes membros: primeiro
nome, sobrenome, data de nascimento, cargo na empresa e salário base (mensal). O programa deve exibir todas as informações, conceder um aumento de 10% e, por fim, exibir novamente as informações de todos os funcionários. Crie as funções paymentRaise e showInfo, as quais possuem os seguintes protótipos:


```c
void paymentRaise(Employee *emp, float raise);
void showInfo(Employee emp);
```

A função paymentRaise deve receber como argumentos um ponteiro para uma variável do tipo Employee e um número do tipo float que representa o percentual do aumento. Já a função showInfo recebe apenas uma variável do tipo Employee como argumento.
