function prod_escalar
  params
    _result
    a1
    a2
  endparams

  vars
    i 1
    s 1
  endvars

     %3 = 0
     s = %3
  label startwhile1 :
     %4 = 10
     %5 = i < %4
     ifFalse %5 goto endwhile1
     %6 = a1
     %7 = %6[i]
     %8 = a2
     %9 = %8[i]
     %10 = %7 * %9
     %11 = s + %10
     s = %11
     %12 = 1
     %13 = i + %12
     i = %13
     goto startwhile1
  label endwhile1 :
     _result = s
     return
endfunction

function main
  vars
    i 1
    v1 10
    v2 10
  endvars

     %2 = 0
     i = %2
  label startwhile1 :
     %3 = 10
     %4 = i < %3
     ifFalse %4 goto endwhile1
     %5 =  - i
     v1[i] = %5
     %7 = i * i
     v2[i] = %7
     %9 = 1
     %10 = i + %9
     i = %10
     goto startwhile1
  label endwhile1 :
     pushparam 
     %11 = &v1
     pushparam %11
     %12 = &v2
     pushparam %12
     call prod_escalar
     popparam 
     popparam 
     popparam %13
     writei %13
     writeln
     return
endfunction


