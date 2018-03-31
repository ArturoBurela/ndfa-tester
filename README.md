# Non Deterministic Finite Automaton (NFA) Tester
## Project. Part I
### Arturo Burela

This program reads from a file the elements that define an NFA and indicates if the input string is accepted by the automaton. This program prints if the string was accepted or not and all the accepted transitions.

The file must be defined as follows:

* First row: `Set of states`
* Second row: `Alphabet symbols`
* Third row: `Initial state`
* Fourth row: `Set of final states`
* Fifth row and up: `Transition function`

`Set of states` indicates all the states separated by commas. No whitespaces. Each state may have a name of variable length. Example:
```
q0,A,longerName,q3,q4
```
`Alphabet symbols` indicates the alphabet symbols separated by commas. No whitespaces. (This program actually ignores this line) Example:
```
a,b,c
```
`Initial state` indicates the initial state. Example:
```
q0
```
`Set of final states` indicates the set of final or acceptance states. Example:
```
q4,q0
```
`Transition function` indicates the transition function in the following format: currentState,input:destinationState. Example:
```
q0,a:q2
```
This means that when being in 'q0' state and the next input is 'a' will take us to 'q3' state.

`Epsilon Transitions` are also supported. Epsilon will be represented by '&' character. Example:
```
q0,&:q3
```
This means '&' can not be used as another element of `Alphabet symbols`.
## Usage instructions

This program has been tested on Debian 9 and MacOS 10.12. It is necessary to have a C++11 compiler. There is a makefile to facilitate the process, clone the project in any desired location, enter to the project directory and type `make` in the terminal to compile the program.

To use the program, first create the NFA file as described previously. Here is an example of a full NFA file:
```
q0,A,longerName,q3,q4
a,b,c
q0
q4
q0,a:A
q0,a:longerName
q0,b:longerName
q0,b:q3
A,a:q3
A,b:q3
longerName,a:longerName
longerName,b:q3
q3,&:q4
q3,a:q4
```

The program receives the NFA filename as the first argument and the string to test as second argument. For example to use the nfa file 'nfa1.txt' and test string 'ab' the program must be called like this:
```
./nfa nfa1.txt ab
```
The programs will make the test and print the results.

## Program Explanation

This program was developed in C++,.
```
// in app.js
// We must declare the bundle!
bundles: [ 'ncc-ecommerce' ],
modules: {
  'ncc-ecommerce': {},
  'ncc-ecommerce-pages': {},
  'ncc-ecommerce-widgets': {},
  'apostrophe-pages': {
    // We must list `ncc-ecommerce-page` as one of the available page types
    types: [
      {
        name: 'ncc-ecommerce-page',
        label: 'Blog'
      },
      {
        name: 'default',
        label: 'Default'
      },
      {
        name: 'home',
        label: 'Home'
      }
    ]
  }
}
```
