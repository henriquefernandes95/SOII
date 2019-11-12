#bin.sh
echo Deseja o horário? s ou n
read x
if [ $x = 's' ] 
    then
        echo "O horário é:"
        date +%X #exibe somente o horario d)
fi
echo Deseja saber o uso \do disco? s ou n
read x
if [ $x = 's' ] 
    then
        echo "O uso do disco é:"
        du /* -hsxc 2>/dev/null | grep -w [0-9]*[GMK] #retorna o uso dos dados com aparencia amigavel e desviando os possiveis erros para o null, obtendo somente os dados relevantes
fi
echo Deseja os usuários? s ou n
read x
if [ $x = 's' ]  
    then
        echo "Os usuários logados são:"
        who #lista os usuários logados
fi
