# D1
d1 <- c(1.260755,
        1.213225,
        1.174489,
        1.205431,
        1.194353,
        1.208997,
        1.199721,
        1.195563,
        1.202116,
        1.198678,
        1.197336,
        1.201236
)

# D2
d2 <- c(7.647711,
        10.542806, 
        14.902179, 
        21.077896, 
        29.690281, 
        41.673500, 
        58.996269, 
        83.113731, 
        117.424240,
        166.031342,
        234.670700,
        331.748474
)
# D3
d3 <- c(17.743305,
        27.612823,
        42.970650,
        68.340012,
        107.086990,
        169.648270,
        267.046692,
        422.624451,
        668.387207,
        1059.177002,
        1676.587891,
        2657.501221
)

# D4
d4 <- c(28.743078,
        46.845009,
        78.330147,
        129.268555,
        216.691132,
        360.736938,
        602.683228,
        1010.026550,
        1688.964111,
        2825.677490,
        4742.051758,
        7948.265625)

n <- c(128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144)


plot(n, d1, type="b", main="Average weight of MST for random edge lengths", ylab="Avg. Weight")
plot(n, d2, type="b", main="Average weight of MST in Dimension 2", ylab="Avg. Weight")
plot(n, d3, type="b", main="Average weight of MST in Dimension 3", ylab="Avg. Weight")
plot(n, d4, type="b", main="Average weight of MST in Dimension 4", ylab="Avg. Weight")



genguess <- function(x) {
  1^2 *10 / x + 0.01 + (1-1) * 0.05
}

guess <- function(x) {
  10/x + 0.001
}

plot(n, qbeta(0.999, 1, n-1), main="0.999 quantile of min of (n-1) random uniforms", ylab = "Quantiles", xlab="n")
guess(n) - qbeta(0.999, 1, n)
curve(guess, add = TRUE)
curve(genguess, add = TRUE)

g1 <- function(x) {
  x^(1/2)/2
}
g2 <- function(x) {
  x^(2/3)/2
}
g3 <- function(x) {
  x^(3/4)/2
}
