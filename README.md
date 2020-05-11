<p align="center">
  <img width="300" src="doc/logo/logo_big.png">
</p>

# Fondamenti di Informatica II e Lab - UNIMORE
[![License](https://img.shields.io/github/license/prittt/Fondamenti-II)](https://github.com/prittt/Fondamenti-II/blob/master/LICENSE)
[![Docs](https://readthedocs.org/projects/pip/badge/?version=latest&style=flat)](https://prittt.github.io/Fondamenti-II/)

<p align="justify">
Questo repository è principalmente rivolto agli studenti di Fondamenti di Informatica II e Lab del Corso di Laurea Triennale in Ingegneria Informatica del Dipartimento di Ingegneria "Enzo Ferrari" dell'Università degl Studi di Modena e Reggio Emilia. Il repository contiene le primitive di liste, alberi e heap viste a lezione ed usate per le esercitazioni. Si noti che le implementazioni fornite sono implementazioni "semplificate", sviluppate a scopo puramente didattico. 
</p>

<p align="justify">
La struttura del progetto è la seguente: 
</p>

```
.
├── list
|   ├── int
|   |   ├── examples
|   |   |   ├── ins_ord.c
|   |   |   ├── iterate.c
|   |   ├── list_int.h
|   |   ├── list_int.c
|   ├── vector
|   |   ├── examples
|   |   |   ├── iterate.c
|   |   ├── list_vector.h
|   |   ├── list_vector.c
+-- tree
+-- heap
+-- ...

```

<p align="justify">
Come potete notare il codice relativo ad una specifica struttura dati si trova in una sottocartella con lo stesso nome: `list`, `tree`, `heap`. Per ognuna di queste vengono fornite diverse implementazioni a seconda del tipo di dato. Le dichiarazioni e le definizioni sono riportate rispettivamente nei nei file `.h` e `.c` in una specifica sottocartalle a seconda del tipo: `int`, `vector`, ecc.  
<p>

<p align="justify">
Quindi ad esempio nella cartella `list>int` troviamo i file `list_int.h` e `list_int.c` che forniscono l'implementazione delle liste per il tipo `int`. 
<p>

<p align="justify">
Nelle sottocartelle `examples` sono disponibili dei file `*c` contenenti dei `main()` di esempio di utilizzo delle primitive.
<p>

<p align="justify">
Il restante materiale è utilizazto per la gestione del repository: generazione automatica della documentazione, generazione del progetto, ecc e può essere pertanto ignorato. Nel seguito di questa pagina troverete i link alla documentazione delle primitive e i link per il download diretto di primitive specifiche. 
</p>

## Liste

| Tipo di Dato | Documentazione | Primitive |
|--------------|----------------| ----------|
| `int`        | <a href="">list_int.html</a> | <a href="">list_int.zip</a> |