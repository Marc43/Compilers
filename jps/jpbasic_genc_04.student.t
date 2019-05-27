function f1
  params
    a
    b
  endparams

  vars
    c 1
    d 1
    found 1
  endvars

     %1 = 0
     found = %1
     %2 = 0.7
     %3 = float a
     %3 = %3 +. %2
     c = %3
     %4 = 0
     d = %4
     %5 = a + d
     %6 = %5 <= c
     %6 = not %6
     %7 = not found
     %8 = %6 or %7
     ifFalse %8 goto endif1
  label startwhile1 :
     %9 = 0
     %10 = b <= %9
     %10 = not %10
     ifFalse %10 goto endwhile1
     %11 = 1
     %12 = b - %11
     b = %12
     %13 = 1
     found = %13
     goto startwhile1
  label endwhile1 :
  label endif1 :
     %14 = 11
     %15 = b <= %14
     ifFalse %15 goto endif2
     %16 = 2
     %17 = float %16
     %17 = %17 *. c
     %18 = 1
     %19 = float %18
     %19 = %17 +. %19
     c = %19
  label endif2 :
     writef c
     writeln
     return
endfunction

function main
  vars
    a 1
    b 1
  endvars

   %1 = 4
   a = %1
   %2 = 2
   %3 = %2 * a
   %4 = 1
   %5 = %3 + %4
   b = %5
   pushparam b
   %6 = 3
   %7 = %6 + b
   pushparam %7
   call f1
   popparam 
   popparam 
   return
endfunction


