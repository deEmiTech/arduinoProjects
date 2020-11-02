### tradutorParaCodigoMorse.ino
 #### O sketch apresenta a seguinte mensagem de erro:
 ```
In function 'void loop()':
tradutorParaCodigoMorse:54:5: error: expected '}' before 'else'
     else if(msg == ' ')
     ^~~~
 At global scope:
tradutorParaCodigoMorse:59:1: error: expected declaration before '}' token
 }
 ^
exit status 1
expected '}' before 'else'
```
O problema é que na verdade não quero fechar a chave porque se fechar, este `else if` sairá de dentro de um outro `if`

Por Favor se tiver alguma sugestão faça um pull request. Agradeço desde já.
