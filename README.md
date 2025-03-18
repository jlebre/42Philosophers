# Philosophers

<p align="center">
  <img src="https://user-images.githubusercontent.com/94384240/171533800-b1fa7318-f18e-44ba-a03f-69bb45900098.jpeg" alt="42 School Logo" width="300">
</p>

## 🧘 42 Cursus - Philosophers

This project is an introduction to multithreading and process synchronization.

The goal is to solve the classic **Dining Philosophers** problem using **threads**, **mutexes**, and **semaphores** in C.

📜 To see the project subject, [click here](https://github.com/jlebre/42Philosophers/blob/main/philo.pdf)!

---

## 📂 Important Files

🔹 To see the `.h` file, [click here](https://github.com/jlebre/42Philosophers/blob/main/philosophers.h)!

🔹 To see the `Makefile`, [click here](https://github.com/jlebre/42Philosophers/blob/main/Makefile)!

🔹 [Main Function](https://github.com/jlebre/42Philosophers/blob/main/srcs/main.c)

---

## ⚙️ How to Use

### 1️⃣ Clone the Repository
```bash
git clone https://github.com/jlebre/42Philosophers.git
cd 42Philosophers
```

### 2️⃣ Compile the Program
```bash
make
```

### 3️⃣ Run the Simulation
```bash
./philosophers [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [optional: number_of_times_each_philosopher_must_eat]
```

Example:
```bash
./philosophers 5 800 200 200
```
This runs a simulation with **5 philosophers**, where:
- Each philosopher will **die** if they do not eat within **800ms**.
- Eating takes **200ms**.
- Sleeping takes **200ms**.

---

## 🧑‍🏫 Understanding the Problem

![dining-philosopher-problem-using-semaphores-1-1643507259](https://github.com/user-attachments/assets/2573b3fb-6fef-41c4-a40f-42e42e288a5a)

The **Dining Philosophers** problem consists of philosophers sitting at a table with one fork between each of them. Each philosopher needs two forks to eat but can only pick up one fork at a time. The challenge is to prevent deadlocks and starvation.

### 💡 Key Challenges
- **Race conditions**: Ensuring multiple threads don’t access shared data improperly.
- **Deadlocks**: Avoiding situations where philosophers hold one fork each and wait indefinitely.
- **Starvation**: Ensuring all philosophers get a chance to eat.

---

## 📊 Output Example
```bash
0 ms: Philosopher 1 is thinking
5 ms: Philosopher 2 is thinking
10 ms: Philosopher 3 is eating 🍽
15 ms: Philosopher 4 is sleeping 😴
...
```

---

## 🧪 Tester

Just run
```bash
./basic_tests.sh
```

---

## 🔗 Some links I used

### Threads 
-[Thread in Operating System](https://www.geeksforgeeks.org/thread-in-operating-system/)  
-[Introduction to Linux Threads – Part I](https://www.thegeekstuff.com/2012/03/linux-threads-intro/)  
-[Linux threads: Creation, Data passing, Waiting](https://iq.opengenus.org/linux-thread-creation-data-passing-waiting/#:~:text=Linux%20threads%3A%20Creation%2C%20Data%20passing%2C%20Waiting%201%20Introduction.,Attributes.%20...%206%20Summary.%20...%207%20References.%20)  

### Mutex 
-[How to Use Mutex Lock in C](https://www.delftstack.com/howto/c/mutex-in-c/)  
-[Mutex lock for Linux Thread Synchronization](https://www.geeksforgeeks.org/mutex-lock-for-linux-thread-synchronization/)  

### GETTIMEOFDAY  
-[How to use gettimeofday function in C language?](https://linuxhint.com/gettimeofday_c_language/)

---

![image](https://github.com/user-attachments/assets/63c3e497-38e6-4582-8b1d-2bdbc13970c8)

