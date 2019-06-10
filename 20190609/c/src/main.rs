macro_rules! input {
    (source = $s:expr, $($r:tt)*) => {
        let mut iter = $s.split_whitespace();
        let mut next = || { iter.next().unwrap() };
        input_inner!{next, $($r)*}
    };
    ($($r:tt)*) => {
        let stdin = std::io::stdin();
        let mut bytes = std::io::Read::bytes(std::io::BufReader::new(stdin.lock()));
        let mut next = move || -> String{
            bytes
                .by_ref()
                .map(|r|r.unwrap() as char)
                .skip_while(|c|c.is_whitespace())
                .take_while(|c|!c.is_whitespace())
                .collect()
        };
        input_inner!{next, $($r)*}
    };
}

macro_rules! input_inner {
    ($next:expr) => {};
    ($next:expr, ) => {};

    ($next:expr, $var:ident : $t:tt $($r:tt)*) => {
        let $var = read_value!($next, $t);
        input_inner!{$next $($r)*}
    };
}

macro_rules! read_value {
    ($next:expr, ( $($t:tt),* )) => {
        ( $(read_value!($next, $t)),* )
    };

    ($next:expr, [ $t:tt ; $len:expr]) => {
        (0..$len).map(|_| read_value!($next, $t)).collect::<Vec<_>>()
    };

    ($next:expr, chars) => {
        read_value!($next, String).chars().collect::<Vec<char>>()
    };

    ($next:expr, usize1) => {
        read_value!($next, usize) - 1
    };

    ($next:expr, $t:ty) => {
        $next().parse::<$t>().expect("Parse error")
    };
}

fn nostep(x: i32, va: &Vec<i32>) -> bool {
    for a in va {
        if *a > x {
            return false;
        }

        if *a == x {
            return true;
        }
    }
    false
}

fn step(x: i32, a: &Vec<i32>, memo: &mut Vec<i32>) -> i32 {
    // println!("x: {}", x);
    if nostep(x, &a.clone()) {
        return 0;
    }

    if x < 2 {
        return 1;
    }

    if memo[x as usize] >= 0 {
        // println!("x: {} memo", x);
        return memo[x as usize];
    }
    let res = step(x - 1, a, memo) + step(x - 2, a, memo);
    let res2 = res % 1000000007;

    memo[x as usize] = res2;
    // println!("x: {} no memo", x);
    return res2;
}

fn main() {
    input! {
        n: i32,
        m: i32,
        a: [i32;m],
    }
    let mut memo = vec![-1; 100000];

    let res = step(n, &a, &mut memo);
    println!("{}", res);
}
