%Lista de alumnos
alumno(aaron, 20161002436, m, is).
alumno(kevin, 20161003333, m, is).
alumno(miriam, 20161002222, f, is).
alumno(juan, 20171001111, m, ic).
alumno(orlando, 20091004444, m, ic).
alumno(juan, 20091001111, m, iq).
alumno(tony, 20091002222, m, mm).
alumno(rony, 20091003333, m, mm).
alumno(kenneth, 20091005555, m, iq).

%Listar alumnos por carrera
alumno_x_carrera(X):- alumno(Z,_,_,X), write(Z).

%Lista de clases
clase(lenguajes, is).
clase(circuitos_electricos, is).
clase(topografia, ic).
clase(sanitaria, ic).
clase(redes1, is).
clase(quimica, iq).
clase(calculo, mm).
clase(ecuaciones, mm).

%Listar clases por carrera
clase_x_carrera(X):- clase(Z,X), write(Z).

%Lista de calificaciones por alumno
clases_cursadas(20161002436,clases(lenguajes,circuitos_electricos),notas(65,62)).
clases_cursadas(20161003333,clases(redes1,circuitos_electricos),notas(98,65)).
clases_cursadas(20161002222,clases(circuitos_electricos),notas(75)).
clases_cursadas(20171001111,clases(topografia),notas(89)).
clases_cursadas(20091004444,clases(topografia, sanitaria),notas(95,26)).
clases_cursadas(20091001111,clases(quimica),notas(100)).
clases_cursadas(20091002222,clases(calculo),notas(63)).
clases_cursadas(20091003333,clases(ecuaciones),notas(67)).
clases_cursadas(20091004444,clases(quimica),notas(90)).


%Promedio Total
promedio_alumno(X,N,M,O):- clases_cursadas(X,_,L),promedioCalculo(L,N,M,O).
promedioCalculo(L,N,M,O):- L =.. [_|Lista], calcularpr(Lista,N,M,O).
calcularpr(Lista,N,M,O) :- sumar(Lista,N), contar(Lista,M), O is N/M.

%Lista de alumnos por clase y promedio
cursando_clase(lenguajes, 20161003333, 99).
cursando_clase(lenguajes, 20161002222, 64).
cursando_clase(sanitaria, 20171001111, 98).
cursando_clase(redes1, 20161002436, 75).
cursando_clase(redes1, 20161002222, 75).
cursando_clase(calculo, 20091003333, 70).
cursando_clase(ecuaciones, 20091002222, 76).

%Listar Alumnos por Clase y Promedio
listar_alumnos_x_clase_y_prom(X):- cursando_clase(X,Y,Z), alumno(N,Y,_,_), write(N), write('||'), write(Y), write('||'), write(Z).

%Listar Alumnos por Clase y Promedio
listar_alumnos_x_clase_prom_y_obs(X):- cursando_clase(X,Y,Z), alumno(N,Y,_,_), write(N), write('||'), write(Y), write('||'), write(Z), write('||'), revisar(Z).


%Sumar Notas
sumar([],0).
sumar([A|B],S):-sumar(B,C), S is C+A.

%Contar notas
contar([],0).
contar([_|L],T):-contar(L,T1),T is T1+1.

%Observacion
revisar(Nota):- Nota<65 -> write('----REPROBO----').
revisar(Nota):- Nota>=65 -> write('----APROBO----').

%Assert
:- dynamic alumno/4.
:- dynamic clases_cursadas/3.
