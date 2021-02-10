<p align="center">
  <img width="300" src="doc/logo/logo_big.png">
</p>

# Fondamenti di Informatica II e Lab - UNIMORE
[![License](https://img.shields.io/github/license/prittt/fondamenti-ii)](https://github.com/prittt/fondamenti-ii/blob/master/LICENSE)
[![Docs](https://readthedocs.org/projects/pip/badge/?version=latest&style=flat)](https://github.com/prittt/fondamenti-ii/blob/master/README.md#doc)
[![Build Status](https://travis-ci.com/prittt/fondamenti-ii.svg?token=uFxAjG3MrtqGf83nu4qz&branch=master)](https://travis-ci.com/prittt/fondamenti-ii)

<p align="justify">
Questo repository è principalmente rivolto agli studenti di Fondamenti di Informatica II e Lab del Corso di Laurea Triennale in Ingegneria Informatica del Dipartimento di Ingegneria "Enzo Ferrari" dell'Università degli Studi di Modena e Reggio Emilia. Il repository contiene le primitive di liste, alberi e heap viste a lezione ed usate per le esercitazioni. Si noti che le implementazioni fornite sono implementazioni "semplificate", sviluppate a scopo puramente didattico. 
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
|   ├── int_vector
|   |   ├── examples
|   |   |   ├── iterate.c
|   |   ├── list_vector.h
|   |   ├── list_vector.c
+-- tree
+-- min-heap
+-- ...

```

<p align="justify">
Come potete notare, il codice relativo ad una specifica struttura dati si trova in una sottocartella con lo stesso nome: <code>list</code>, <code>tree</code>, <code>min-heap</code>. Per ognuna di queste vengono fornite diverse implementazioni a seconda del tipo di dato. Le dichiarazioni e le definizioni sono riportate rispettivamente nei nei file <code>.h</code> e <code>.c</code> in una specifica sottocartelle a seconda del tipo: <code>int</code>, <code>int_vector</code>, ecc.  
</p>

<p align="justify">
Quindi, ad esempio, nella cartella <code>list>int</code> troviamo i file <code>list_int.h</code> e <code>list_int.c</code> che forniscono l'implementazione delle liste per il tipo <code>int</code>. 
</p>

<p align="justify">
Nelle sottocartelle <code>examples</code> sono disponibili dei file <code>.c</code> contenenti dei <code>main()</code> di esempio di utilizzo delle primitive.
</p>

<p align="justify">
Il restante materiale è utilizzato per la gestione del repository: generazione automatica della documentazione, generazione del progetto, ecc e può essere pertanto ignorato. Nel seguito di questa pagina troverete i link alla documentazione delle primitive e i link per il download diretto di primitive specifiche. 
</p>

<h2><a name="doc">Documentazione</a></h2>

### Liste (Singly Linked List)

| Tipo di Dato | Documentazione | Sorgente Primitive | 
|--------------|----------------|--------------------|
| `int`        | <a href="https://prittt.github.io/fondamenti-ii/list/int/html/index.html">list_int.html</a> | <a href="https://prittt.github.io/fondamenti-ii/list/int/list_int.zip">list_int.zip</a> |
| `int_vector` | <a href="https://prittt.github.io/fondamenti-ii/list/int_vector/html/index.html">list_int_vector.html</a> | <a href="https://prittt.github.io/fondamenti-ii/list/int_vector/list_int_vector.zip">list_int_vector.zip</a> |

### Alberi (Binary Tree)

| Tipo di Dato | Documentazione | Sorgente Primitive | 
|--------------|----------------|--------------------|
| `int`        | <a href="https://prittt.github.io/fondamenti-ii/tree/int/html/index.html">tree_int.html</a> | <a href="https://prittt.github.io/fondamenti-ii/tree/int/tree_int.zip">tree_int.zip</a> |
| `char`        | <a href="https://prittt.github.io/fondamenti-ii/tree/char/html/index.html">tree_char.html</a> | <a href="https://prittt.github.io/fondamenti-ii/tree/int/tree_char.zip">tree_char.zip</a> |

### Min-Heap (Array-Based Binary Min-Heap)

| Tipo di Dato | Documentazione | Sorgente Primitive | 
|--------------|----------------|--------------------|
| `int`        | <a href="https://prittt.github.io/fondamenti-ii/min-heap/int/html/index.html">minheap_int.html</a> | <a href="https://prittt.github.io/fondamenti-ii/min-heap/int/min-heap_int.zip">minheap_int.zip</a> |