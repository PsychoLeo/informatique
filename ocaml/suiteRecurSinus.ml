let next un = sin(un);;

let un u0 n = 
    let r = ref u0 in
    for i=1 to n do
        r := next(!r);
    done;
    !r
;;

print_string "u0 = ";;
let u0 = read_float();;
print_string "n = ";;
let n = read_int();;
let r = un u0 n;;
print_string "u_n = ";;
print_int r;;
print_string "u_n/(3/sqrt n) = ";;
let rapport = sqrt(3. /. r);;