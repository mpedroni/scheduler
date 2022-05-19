# scheduling policies

Este repositório contém a implementação de diferentes políticas de escalonamento a fim de atender os critérios do trabalho proposto, cujo enunciado é

> Para consolidar o aprendizado sobre os escalonadores, você deverá implementar algoritmos de escalonadores de tarefas (taks) estudos em aula. Os escalonadores são o Round-Robin (RR), Shortest-Job First (SJF) e Round-Robin com prioridade baseado em FIFO (RR_p_FIFO). Para essa implementação, são disponibilizados os seguintes arquivos:
>
> - driver (.c) – implementa a função main(), a qual lê os arquivos com as informações das tasks de um arquivo de teste (fornecido), adiciona as tasks na lista (fila de aptos) e chama o escalonador.
> - CPU (.c e .h) – esses arquivos implementam o monitor de execução, tendo como única funcionalidade exibir (via print) qual task está em execução no momento.
> - list (.c e .h) - esses arquivos são responsáveis por implementar a estrutura de uma lista encadeada e as funções para inserção, deletar e percorrer a lista criada.
> - task (.h) – esse arquivo é responsável por descrever a estrutura da task a ser manipulada pelo escalonador (onde as informações são armazenadas ao serem lidas do arquivo).
> - scheduler (.h) – esse arquivo é responsável por implementar as funções de adicionar as task na lista (função add()) e realizar o escalonamento (schedule()). Esse é um arquivo base que deve ser usado para implementar todos os algoritmos pedidos. **Esse arquivo deve ser o implementado por vocês. Você irá gerar as versões do algoritmo de escalonamento, RR, SJF e RR_p_FIFO, em projetos diferentes.**

## Executando as políticas de escalonamento

Para executar a política desejada, basta incluir o arquivo correspondente a ela no arquivo `driver.c` e executar o comando `make <policy>`. Os arquivos e comando correspondentes à cada política são os seguintes:
| Policy | Arquivo | Comando `make` |
|------------------------|-----------------------|--------------------|
| Smallest-Job First | `schedule_sjf.c` | `make sjf` |
| Round Robin | `schedule_rr.c` | `make rr` |
| Round Robin + Priority | `schedule_rrp_fifo.c` | `make priority_rr` |
