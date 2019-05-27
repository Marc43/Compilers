function main
  vars
    a 1
    b 1
    end 1
    pi 1
  endvars

   %1 = 12
   a = %1
   %2 = 5
   %3 = a * %2
   %4 = 1
   %5 = a + %4
   %6 = a * %5
   %7 = %3 + %6
   b = %7
   %8 = b < a
   %8 = not %8
   %9 = 0
   %10 = a == %9
   %11 = not %10
   %12 = %8 and %11
   end = %12
   %13 = 3.3
   %14 = 1
   %15 = %14 / a
   %16 = float %15
   %16 = %13 +. %16
   %17 = 2.0
   %18 =  -. %17
   %19 = float a
   %19 = %18 /. %19
   %20 = %16 -. %19
   pi = %20
   %21 = a == b
   %22 = %21 or end
   writei %22
   writeln
   %24 = a * b
   writei %24
   writeln
   %26 = 2
   %27 = float %26
   %27 = %27 *. pi
   writef %27
   writeln
   return
endfunction


