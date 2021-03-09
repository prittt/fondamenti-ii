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
├── elemtype
|   ├── int
|   |   ├── elemtype.h
|   |   ├── elemtype.c
|   ├── char
|   |   ├── elemtype.h
|   |   ├── elemtype.c
|   ├── int_vector
|   |   ├── elemtype.h
|   |   ├── elemtype.c
|   ├── ...
├── list
|   ├── int
|   |   ├── examples
|   |   |   ├── ins_ord.c
|   |   |   ├── iterate.c
|   ├── int_vector
|   |   ├── examples
|   |   |   ├── iterate.c
|   ├── list.h
|   ├── list.c
├── tree
├── minheap
├── ...

```

<p align="justify">
Come potete notare, il codice relativo ad una specifica struttura dati si trova in una sottocartella con lo stesso nome: <code>list</code>, <code>tree</code>, <code>minheap</code>. Per ognuna di queste viene fornita un'unica implementazione generica che non dipende dal tipo di dato. Le dichiarazioni e le definizioni di <code>ElemType</code> per uno specifico tipo di dato le trovate in sottocartelle di <code>elemtype</code>, rispettivamente nei file <code>.h</code> e <code>.c</code>. Le implementazioni di liste, alberi, e heap devono essere accompagnate da un'implementazione specifica di <code>ElemType</code> per funzionare correttamente.
</p>

<p align="justify">
Ad esempio, nella cartella <code>list</code> troviamo i file <code>list.h</code> e <code>list.c</code> che forniscono l'implementazione delle liste e che dovranno essere accompagnati dalla definizione di <code>ElemType</code> e dall'implementazione delle funzioni a esso associate. Se vogliamo utilizzizare liste di `int`, ad esempio, avremo bisogno anche dei file <code>elemtype>int>elemtype.h</code> e <code>elemtype>int>elemtype.c</code>.
</p>

<p align="justify">
Nelle sottocartelle <code>examples</code> sono disponibili dei file <code>.c</code> contenenti delle funzioni di esempio di utilizzo delle primitive.
</p>

<p align="justify">
Il restante materiale è utilizzato per la gestione del repository: generazione automatica della documentazione, generazione del progetto, ecc e può essere pertanto ignorato. Nel seguito di questa pagina troverete i link alla documentazione delle primitive e i link per il download diretto di primitive specifiche, ovvero primitive accompagnare ad una specifica implementazione di <code>ElemType</code>. 
</p>

<h2><a name="doc">Documentazione</a> e Funzioni Primitive</h2>

### Liste (Singly Linked List)

| Tipo di Dato | Documentazione | Sorgente Primitive | 
|--------------|----------------|--------------------|
| `int`        | <a href="https://prittt.github.io/fondamenti-ii/list/int/html/index.html">list_int.html</a> | <a href="https://prittt.github.io/fondamenti-ii/list/int/list_int.zip">list_int.zip</a> |
| `int_vector` | <a href="https://prittt.github.io/fondamenti-ii/list/int_vector/html/index.html">list_int_vector.html</a> | <a href="https://prittt.github.io/fondamenti-ii/list/int_vector/list_int_vector.zip">list_int_vector.zip</a> |

### Alberi (Binary Tree)

| Tipo di Dato | Documentazione | Sorgente Primitive | 
|--------------|----------------|--------------------|
| `int`        | <a href="https://prittt.github.io/fondamenti-ii/tree/int/html/index.html">tree_int.html</a> | <a href="https://prittt.github.io/fondamenti-ii/tree/int/tree_int.zip">tree_int.zip</a> |
| `char`        | <a href="https://prittt.github.io/fondamenti-ii/tree/char/html/index.html">tree_char.html</a> | <a href="https://prittt.github.io/fondamenti-ii/tree/char/tree_char.zip">tree_char.zip</a> |

### Min-Heap (Array-Based Binary Min-Heap)

| Tipo di Dato | Documentazione | Sorgente Primitive | 
|--------------|----------------|--------------------|
| `int`        | <a href="https://prittt.github.io/fondamenti-ii/minheap/int/html/index.html">minheap_int.html</a> | <a href="https://prittt.github.io/fondamenti-ii/minheap/int/minheap_int.zip">minheap_int.zip</a> |
