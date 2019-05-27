function f
  params
    a
  endparams

   %2 = 5
   %3 = 5
   %4 = a
   %5 = %4[%3]
   %6 = 10
   %7 = float %6
   %7 = %5 *. %7
   %8 = a
   %8[%2] = %7
   return
endfunction

function main
  vars
    b 10
    c 10
  endvars

   %2 = 5
   readf %3
   b[%2] = %3
   %4 = 7
   %5 = 5
   %6 = b[%5]
   c[%4] = %6
   %8 = 5
   %9 = b[%8]
   writef %9
   writeln
   %11 = 7
   %12 = c[%11]
   writef %12
   writeln
   %14 = &b
   pushparam %14
   call f
   popparam 
   %15 = 5
   %16 = b[%15]
   writef %16
   writeln
   %18 = 7
   %19 = c[%18]
   writef %19
   writeln
   return
endfunction


