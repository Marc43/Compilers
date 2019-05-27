function x2
  params
    _result
    a
  endparams

  vars
    i 1
    n 1
  endvars

     %2 = 0
     n = %2
     %3 = 0
     i = %3
  label startwhile1 :
     %4 = 10
     %5 = i < %4
     ifFalse %5 goto endwhile1
     %6 = a
     %7 = %6[i]
     %8 = 0
     %9 = %7 == %8
     ifFalse %9 goto endif1
     %10 = 1
     %11 = n + %10
     n = %11
  label endif1 :
     %12 = a
     %13 = %12[i]
     %14 = 2
     %15 = %13 * %14
     %16 = a
     %16[i] = %15
     %17 = a
     %18 = %17[i]
     writei %18
     writeln
     %20 = 1
     %21 = i + %20
     i = %21
     goto startwhile1
  label endwhile1 :
     _result = n
     return
endfunction

function main
  vars
    x 10
    i 1
    z 1
  endvars

     %2 = 0
     i = %2
  label startwhile1 :
     %3 = 10
     %4 = i < %3
     ifFalse %4 goto endwhile1
     x[i] = i
     %6 = 1
     %7 = i + %6
     i = %7
     goto startwhile1
  label endwhile1 :
     %8 = 0
     i = %8
  label startwhile2 :
     %9 = 10
     %10 = i < %9
     ifFalse %10 goto endwhile2
     %11 = x[i]
     writei %11
     writeln
     %13 = 1
     %14 = i + %13
     i = %14
     goto startwhile2
  label endwhile2 :
     pushparam 
     %15 = &x
     pushparam %15
     call x2
     popparam 
     popparam %16
     z = %16
     %17 = 'z'
     writec %17
     %17 = ':'
     writec %17
     writei z
     writeln
     %19 = 0
     i = %19
  label startwhile3 :
     %20 = 10
     %21 = i < %20
     ifFalse %21 goto endwhile3
     %22 = 'x'
     writec %22
     %22 = '['
     writec %22
     writei i
     %23 = ']'
     writec %23
     %23 = '='
     writec %23
     %24 = x[i]
     writei %24
     writeln
     %26 = 1
     %27 = i + %26
     i = %27
     goto startwhile3
  label endwhile3 :
     return
endfunction


