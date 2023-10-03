
## Q1
### a)
#### i) Differences between information security and cyber security

Information security addresses the security of information and data sources.
Addresses the security issues with cyber physical medium sources


#### ii) Two basic assumptions in cryptography

- All cryptographic algorithms are known to public
- Keys are private

#### iii) Explain CIA triad concepts

The data sources must preserve their _confidentiality_ and _integrity_, while maintaining their _availability_
- **Confidentiality** - Unauthorized reading of data sources is prevented
- **Integrity** - Unauthorized writing and modification is prevented
- **Availability** - Provide timely and reliable access to information


### b)
#### i) Use double transposition cipher to decrypt

Ciphertext = "EBIGNUDTxNOCWOxN"
Key = [1324], [2143]

Plaintext = "BEGIN COUNTDOWN "

#### ii) Decrypt Ciphertext "EPRSPACTO" with the OTP "RTCASCEOP". Refer to the table

Plaintext : "TOPSECRET"

#### iii) Depth issues with the OTP

When multiple messages are encrypted with the same pad, it is known as a depth.
Cryptanalysts can use this to carry out a brute force attack since C<sub>1</sub> + C<sub>2</sub> = P<sub>1</sub> + P<sub>2</sub>


#### iv) Which of confusion and diffusion is used in OTPs and Double transposition cipher?

- **OTP** : Only confusion is used. Because the plaintext's information is not spread out in the ciphertext.
- **Double Transposition Cipher** : Both confusion and diffusion are used in double transposition cipher. There is an obscure relationship between the plaintext and the ciphertext and also the plaintext details are statistically spread in the ciphertext


## Q2

### a)

#### i) How stream ciphers work? State two commonly used stream ciphers.

Stream ciphers take the whole plaintext and encrypts one digit/bit at a time
- A5/1
- RC4

#### ii) Explain expansion, permutation, substitution, and XOR.

- **Expansion** : Used to increase the size of a data block. Takes an input data block and outputs a larger data block. Used in DES to expand 32 bit block to 48 bit block.
- **Permutation** : Used to rearrange the bits within a data block to achieve a specific shuffling or scrambling effect. In DES, the permutation operation (P-box) is used to shuffle the bits in the right half of the data block before mixing them with the results of other operations.
- **Substitution** : Used to replace or substitute certain bits or blocks of bits within a data block with new values based on a substitution table or S-box. Used in DES to replace 6 bit input by a 4 bit output.
- **XOR** : A basic bitwise operation that combines two sets of bits to produce a result. If the input bits are same, the output is 0 and the input bits are different, the output is 1.


### b) Consider Feistel cipher design with three rounds. L<sub>i</sub> = R<sub>i-1</sub> and R<sub>i</sub> = L<sub>i-1</sub> + F(R<sub>i-1</sub>, K<sub>i</sub>)
#### i) What is the Ciphertext if F(R<sub>i-1</sub>, K<sub>i</sub>) = R<sub>i-1</sub>

P = L<sub>0</sub> , R<sub>0</sub>

L<sub>1</sub> = R<sub>0</sub> 
R<sub>1</sub> =  L<sub>0</sub> + R<sub>0</sub>

L<sub>2</sub> = R<sub>1</sub> = L<sub>0</sub> + R<sub>0</sub>
R<sub>2</sub> =  L<sub>1</sub> + R<sub>1</sub> = R<sub>0</sub> + (L<sub>0</sub> + R<sub>0</sub>) = L<sub>0</sub>

L<sub>3</sub> = R<sub>2</sub> =  L<sub>0</sub>
R<sub>3</sub> =  L<sub>2</sub> + R<sub>2</sub> = (L<sub>0</sub> + R<sub>0</sub>) + L<sub>0</sub>

Ciphertext C = L<sub>0</sub> , R<sub>0</sub>
Ciphertext is the same as plaintext

#### ii) Comment on the security of the previous example

Since P and C are the same, there is no security. A stronger round function can be used to increase the security.


### c) C = E(P, K) and P = D(C, K) Write function for T-DES.

Triple DES uses EDE approach.

C = E( D( E( P, K<sub>1</sub>), K<sub>2</sub>), K<sub>1</sub>)
P = D( E( D( P, K<sub>1</sub>), K<sub>2</sub>), K<sub>1</sub>)

### d) 

#### i) Two drawbacks of EBC mode.

- Cut and paste attack is possible
- Confidentiality is not achieved when encrypting images


#### ii) Analyze how CBC mode recovers when a ciphertext block is changed during transmission

Assume the ciphertext block C<sub>x</sub> is changed to G.

Formula for decryption in CBC mode P<sub>i</sub> = D(C<sub>i</sub> , K) + C<sub>i-1</sub> 

When decrypting, the blocks up to x<sup>th</sup> block are decrypted without an issue since they do not rely on the C<sub>x</sub> block.
When the C<sub>x</sub> block is being decrypted, the x<sup>th</sup> plaintext block P<sub>x</sub> is wrong since it relies on the  block.
	P<sub>x</sub> = D(G , K) + C<sub>x-1</sub>
Similarly, when the C<sub>x+1</sub> block is also wrong since it also depends on the C<sub>x</sub> block.
	P<sub>x+1</sub> = D(C<sub>x+1</sub> , K) + G

However, none of the following blocks are affected since they do not depend on the C<sub>x</sub> block.
Therefore, the CBC mode automatically recovers after two blocks.


## Q3

### a)

#### i) What is the main difference between symmetric key cryptography and asymmetric key cryptography?

- Symmetric key cryptography uses same key for both encryption and decryption processes.
- Asymmetric key cryptography uses two keys for encryption and decryption processes
	- Private key and public key

#### ii) Public key is based on one way trap door function. Explain.

One way trap door function is where computing the result in one way is easy and going back from that is almost infeasible.
	One example is that in RSA algorithm, it take two very large prime numbers and their product. It is easy to multiply the prime numbers, however it is not possible to factor out two prime numbers when their product is given

#### iii) Explain "ECC is a popular method used in cryptographic system to enhance the performance"

ECC uses the mathematical concept of Elliptic curves to employ the trap door function. 
	Here, it is relatively easy to compute the multiplications of a point in the elliptic curve, but it is infeasible to determine the multiplying factor of a point, when the multiplied result is given.
ECC can do this with high efficiency when compared with the Diffie Hellmann algorithm.
	For example, we can get the same level of security of a DH system with ECC having lesser number of bits.


### b)

#### i) Identify private key and the public key

Private key = (N, d)
Public key = (N, e)

#### ii) Find ciphertext C, for p = 5, q = 3 and M = 7

pq = 15
Totient = 8

*Choose e to be co prime with totient and d to be ed = 1 (mod 8)*
e = 3
d = 3

C = M<sup>e</sup> mod N = 7<sup>3</sup> mod 15 = 13

#### iii) Find decrypted plaintext for C = 8

D = C<sup>d</sup> mod N = 8<sup>3</sup> mod 15 = 2


### c) Why is it difficult to figure out shared secret in DH algorithm?

The intruder can see g<sup>a</sup> and g<sup>b</sup>. By multiplying them, the intruder can obtain g<sup>a+b</sup>, but not g<sup>ab</sup> which is the shared secret.
To find g<sup>ab</sup>, a and b must be solved separately because the attacker must solve the discrete log problem to do that.

### d) Alice signs a message, encrypts before sending to Bob.

#### i) Write in public key notations

{ [M]<sub>Alice</sub> }<sub>Bob</sub> 

#### ii) Explain one advantage and one disadvantage.

- One advantage is that the receiver (Bob) can make sure that he is communicating with Alice. Suitable when communicating between many peers
- One disadvantage is that it is very costly.


## Q4

### a)

#### i) What is the difference between Authorization and Authentication

**Authentication** is verifying the identity of a person.
**Authorization** is granting access to a person after bein authenticated

#### ii) Explain three-factor authentication

- Something you _know_ - Password
- Something you _have_ - Debit cards
- Something you _are_ - Fingerprints

#### iii) Explain how dictionary attack works

When selecting a password of 8 characters with 256 possible character samples, the number of random permutations are 8<sup>256</sup>. However, the cryptanalysts can use a set of words which are pre-known to guess the actual password. Therefore the actual number of passwords they have to brute force through is way less than 8<sup>256</sup>. This is known as *dictionary attack*.
We can prevent this by
- Using a salt
- Using hashing

### b) Design a simple authentication protocol between two parties



### c) 

#### i) Draw the access control matrix


|          | Accounting Program |  Accounting Data   |  
| -------- | ------------------ | ------------------ |  
| Shawn    |        rx      |        r      |  
| Peter    |        rwx      |        rw      |


#### ii) ACLs vs C Lists

- ACLs provide the access rights of each subject to a given object.
	- Can be used to manage information of sensitive files
- C Lists provide the access rights of a subject to each object.
	- Can be used to manage user information



## Q5

### a)

#### i) Four properties of a Hash function

- Compression
- Simple
- One way
- Collision resistance

#### ii) Two hash algorithms

- Tiger hash
- SHA 512 hash

#### iii) Avalanche effect?

A small change in input will cause a big change the hash output.


#### iv) Uses of Hash functions?

- Online bidding
- Spam reduction
	- Can force the user to do some effort when sending emails
	- Find R in a way that the hash starts with some pre-defined number of 0s


### b) Flow diagram to explain HMAC

Decrypt the message, Hash the message, sent ciphertext and hash.
Extract hash at the receiving end, decrypt, hash the decrypted message again, and compare with the received hash.


### c)

#### i) One example for using watermarks in detecting misuse

- In money notes


#### ii) How can images be used in steganography.

Information can be inserted into least significant bits of RGB values in images. This won't affect the look of the image since changing LSB by 1 bit is negligible.


### d)

#### i) Difference between virus and worm

Viruses need a host to propagate but worms don't.

#### ii) Types of detections used 

- Signature based detection - used when identifying patterns to detect botnet attacks in Step 4.
- Anomaly based - Used in detecting deviations from the normal profiles in Step 2.
