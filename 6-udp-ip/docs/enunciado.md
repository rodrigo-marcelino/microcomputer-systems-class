# Lab 6 - UDP/IP Communication
## 01-) Time UPD/IP

Elabore um programa cliente, que utilize o protocolo UDP, e seja capaz de se comunicar com
um servidor UDP remoto com endereço 68.183.28.251. Este servidor executa uma instância
do processo conhecido como echoserver, na porta 6666. O aplicativo cliente deve ser capaz de:
1. Enviar mensagens (com qualquer conteúdo) a cada 400 ms para o servidor pelo período
de 20 s.
3. Medir o intervalo de tempo (∆t) entre o momento em que o cliente faz a requisição (treq)
e o momento em que recebe uma resposta (tres) do servidor (∆t = tres − treq).
4. Salvar, em um arquivo texto simples (.dat), os valores de ∆t e t obtidos no item anterior.



## 02-) Time TCP/IP

De forma análoga ao exercício anterior, elabore um programa cliente, desta vez, que utilize
o protocolo TCP, e seja capaz de se comunicar com um servidor TCP remoto com endereço
68.183.28.251. Este servidor executa uma segunda instância do processo echoserver, desta
vez utilizando, também, o protocolo TCP, na porta 6667. O aplicativo cliente deve ser capaz
de:
1. Enviar mensagens (com qualquer conteúdo) a cada 400 ms para o servidor pelo período
de 20 s.
3. Medir o intervalo de tempo (∆t) entre o momento em que o cliente faz a requisição (treq)
e o momento em que recebe uma resposta (tres) do servidor (∆t = tres − treq).
4. Salvar, em um arquivo texto simples (.dat), os valores de ∆t e t obtidos no item anterior.




## 03-) TCP/IP & UDP/IP Comparison

De posse dos dados gerados pelos clientes dos dois aplicativos desenvolvidos nos exercícios
anteriores:
1. Elabore um gráfico de ∆t em função de t para a comunicação entre cliente e servidor para
cada um dos casos, ou seja, uma curva para os resultados obtidos utilizando o protocolo
TCP e outra para os resultados obtidos utilizando o protocolo UDP.
a. Coloque as diferentes curvas no mesmo gráfico para que seja possível visualizar melhor
as diferenças temporais entre as diferentes situações.
2. Calcule a média, variância, desvio padrão e os valores máximo e mínimo de ∆tT CP e ∆tUDP
(dados temporais da comunicação TCP e UDP, respectivamente).
3. Comente sobre as diferenças encontradas e suas possíveis causas.