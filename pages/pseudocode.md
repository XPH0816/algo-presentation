# Pseudocode
Start of Program

```ts{all|2-4|5-8|all}
  Start
	REPEAT
		INPUT choice
	UNTIL choice is between 1 to 3
	CASE choice
		1: CALL Ask Information Module
		2: CALL Read Disk Module
		3: End
```
---

# Pseudocode
Ask Information Module

```ts{all|2-4|6-8|10-12|14-16|18-20|all}
  Start
	REPEAT 
    		INPUT name
	UNTIL name is not empty, and no number contains

	REPEAT
    		INPUT age
	UNTIL age between 1 and 100

	REPEAT
    		INPUT weight
    UNTIL weight is between 1.00 and 300.00

	REPEAT
    		INPUT height
    UNTIL height is between 1.00 and 300.00

	REPEAT
    		INPUT gender
    UNTIL gender is M or F
 End
```

---

# Pseudocode
Calculate Module (1)

```ts{all|2-9|11-15}
 Start
    FUNCTION calculateBMR
        Pass In: Address of user variable
        CASE of User Gender
        'M': COMPUTE BMR = 66 + (weight * 13.7) + (5 * height) – (6.8 * age)
        'F': COMPUTE BMR = 655 + (weight * 9.6) + (1.8 * height) – (4.7 * age)
	    ENDCASE
	ENDFUNCTION
    return BMR

    FUNCTION calculateDCR
        Pass In: Address of user variable
        COMPUTE using formula DCR = BMR * activtyLevelValue
    ENDFUNCTION
    return DCR
    

```

---

# Pseudocode
Calculate Module (2)

```ts{1-9|10|all}
    FUNCTION printInfo
        PRINT user.name
        PRINT user.weight
        PRINT user.height
        PRINT user.gender
        PRINT user.activityLevel
        PRINT calculateBMR
        PRINT calculateDCR
    ENDFUNCTION
 End
```