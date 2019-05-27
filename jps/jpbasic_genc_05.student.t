function f
  params
    _result
    a
    b
  endparams

  vars
    x 1
    y 1
    z 10
  endvars

     %2 = 9
     %3 = 67
     %4 = a + %3
     z[%2] = %4
     %6 = 34
     x = %6
     %7 = 3
     %8 = 56
     %9 = 9
     %10 = z[%9]
     %11 = %8 + %10
     z[%7] = %11
     %13 = 3
     %14 = z[%13]
     %15 = %14 <= x
     %15 = not %15
     ifFalse %15 goto else1
     %16 = 78
     x = %16
     writef b
     writeln
  label else1 :
     %18 = 99
     x = %18
     %19 = 3
     %20 = z[%19]
     writei %20
     writeln
     %22 = 1
     _result = %22
     return
endfunction

function fz
  params
    r
  endparams

  label startwhile1 :
     %1 = 0
     %2 = r <= %1
     %2 = not %2
     ifFalse %2 goto endwhile1
     %3 = 1
     %4 = r - %3
     r = %4
     goto startwhile1
  label endwhile1 :
     return
endfunction

function main
  vars
    a 1
  endvars

     pushparam 
     %1 = 3
     pushparam %1
     %2 = 2
     %2 = float %2
     pushparam %2
     call f
     popparam 
     popparam 
     popparam %3
     ifFalse %3 goto endif1
     %4 = 3.7
     %5 = float a
     %5 = %5 +. %4
     %6 = 4
     %7 = float %6
     %7 = %5 +. %7
     writef %7
     writeln
  label endif1 :
     return
endfunction


