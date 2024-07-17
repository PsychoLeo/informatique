let gcd a b = 
    let aa = ref a in 
    let bb = ref b in
    while !bb > 0 do
        let tmp = ref (!aa mod !bb) in 
        aa := !bb;
        bb := !tmp;
    done;
    !aa
;;

let rec gcdRec a b = 
    if b = 0 then a else gcdRec b (a mod b)
;;

let powInt a n = 
    let r = ref 1 in
    for i=1 to n do
        r := !r * a;
    done;
    !r
;;

let fact n = 
    if n < 0 then 0 else
    let r = ref 1 in
    for i=1 to n do 
        r := !r * i;
    done;
    !r
;;

(*Calcul de l'inverse modulaire de a mod n*)
let modInv a n =
    let r = ref 0 in
    for i=1 to n-1 do
        if ((a*i) mod n) = 1 then r := i else r := 0;
    done;
    !r
;;

print_string "n = ";;
let n = read_int();;
print_string "n! = ";;
print_int (fact n);;
print_newline();;