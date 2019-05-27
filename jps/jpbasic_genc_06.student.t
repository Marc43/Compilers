function f
  params
    _result
    a
    f
  endparams

  vars
    x 1
    b 1
    z 10
  endvars

     %2 = 5
     readi %3
     z[%2] = %3
     %4 = 5
     %5 = z[%4]
     %6 = 88
     %7 = %5 + %6
     writei %7
     readi b
     readf f
     ifFalse b goto endif1
     %8 = 'h'
     writec %8
     writeln
     %8 = '\t'
     writec %8
     %8 = 'l'
     writec %8
     %8 = '\\'
     writec %8
     %8 = 'a'
     writec %8
     %9 =  -. f
     %10 =  -. %9
     %11 =  -. %10
     writef %11
     writeln
  label endif1 :
     %13 = 1
     _result = %13
     return
endfunction

function fz
  params
    _result
    r
    u
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
     %5 = 0
     %6 = r == %5
     ifFalse %6 goto endif1
     pushparam 
     %7 = 55555
     pushparam %7
     %8 = 1
     %9 = 4
     %10 = %8 / %9
     %10 = float %10
     pushparam %10
     call f
     popparam 
     popparam 
     popparam %11
  label endif1 :
     %12 = 3
     %13 = r + %12
     %14 = float %13
     %14 = %14 *. u
     _result = %14
     return
endfunction

function main
  vars
    a 1
    q 1
  endvars

   %1 = 0
   q = %1
   pushparam 
   %2 = 3
   %3 = 4
   %4 = %2 + %3
   pushparam %4
   pushparam 
   %5 = 4444
   pushparam %5
   %6 = 2
   %7 = float %6
   %7 = q +. %7
   pushparam %7
   call fz
   popparam 
   popparam 
   popparam %8
   pushparam %8
   call fz
   popparam 
   popparam 
   popparam %9
   q = %9
   %10 = 3.7
   %11 = q +. %10
   %12 = 4
   %13 = float %12
   %13 = %11 +. %13
   writef %13
   writeln
   return
endfunction


