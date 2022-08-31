#ifndef OPECODE_H__
#define OPECODE_H__

typedef enum opecodes {
    NOP,    
    ADD,  
    SUB,  
    AND,
    OR,
    XOR,
    NOT,
    IN,  
    OUT,    
    LOAD,  
    STOR,    
    JMP,    
    JZ,      
    PUSH,          
    DUP,    
    SWAP,  
    ROL3,    
    OUTNUM,  
    INNUM,    
    JNZ,      
    DROP,  
    COMPL,  
    HLT,
    PUSHIP,
    POPIP,  
    DROPIP
   
}  opecodes;


#endif