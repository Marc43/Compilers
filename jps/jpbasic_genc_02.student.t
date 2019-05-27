function main
  vars
    n 1
    f 1
    aux 1
    end 1
  endvars

     readi n
     aux = n
     %1 = 0
     %2 = n < %1
     ifFalse %2 goto endif1
     %3 = 'n'
     writec %3
     %3 = ' '
     writec %3
     %3 = '>'
     writec %3
     %3 = '='
     writec %3
     %3 = ' '
     writec %3
     %3 = '0'
     writec %3
     %3 = '!'
     writec %3
     writeln
     %4 = 1
     end = %4
  label endif1 :
     %5 = 1
     f = %5
  label startwhile1 :
     %6 = not end
     %7 = 1
     %8 = n <= %7
     %8 = not %8
     %9 = %6 and %8
     ifFalse %9 goto endwhile1
     %10 = f * n
     f = %10
     %11 = 1
     %12 = n - %11
     n = %12
     goto startwhile1
  label endwhile1 :
     %13 = 0
     %14 = end == %13
     ifFalse %14 goto endif2
     writei aux
     %15 = '!'
     writec %15
     %15 = '='
     writec %15
     writei f
     writeln
  label endif2 :
     return
endfunction


