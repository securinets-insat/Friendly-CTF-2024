#!/bin/bash

generate_flag() {
  content=$(cat flag.txt)

  if [ -z "$content" ]; then
    char='n'
    echo "$char" > flag.txt
    content="$char"
  fi

  if [ ${#content} -ge 11 ]; then
    return 0
  fi
  
  encrypt() {
    local input="$1"
    local shift=1
    local output=""

    for (( i=0; i<${#input}; i++ )); do
      char="${input:$i:1}"
      ascii_value=$(printf "%d" "'$char")

      new_ascii_value=$(( ascii_value + shift ))

      if [ "$new_ascii_value" -gt 122 ]; then
        new_ascii_value=65  # Wrap to 'A' when exceeding 'z'
      fi

      next_letter=$(printf "\\$(printf '%03o' "$new_ascii_value")")
      output+="$next_letter"
    done
    
    echo "$output"
  }

  generate_next_char() {
    local input="$1"
    local length=${#input}
    local total_ascii=0

    for (( i=0; i<length; i++ )); do
      char="${input:$i:1}"
      ascii_value=$(printf "%d" "'$char")
      total_ascii=$((total_ascii + ascii_value))
    done
    
    while true; do
      next_char_ascii=$(( total_ascii % 123 ))  
      if [ "$next_char_ascii" -ge 65 ] && [ "$next_char_ascii" -le 122 ]; then
        break
      else
        total_ascii=$((total_ascii + 1))  
      fi
    done
    
    next_char=$(printf "\\$(printf '%03o' "$next_char_ascii")")
    echo "$next_char"
  }

  encrypted_content=$(encrypt "$content")
  echo -n "$encrypted_content" > flag.txt
  
  new_char=$(generate_next_char "$content")

######################## echo the character before any encryption
  echo "$new_char"
######################## and you add the last character that is "t"
# because it won't be printed since the function returns 0 before reaching the echo statement
  
  echo -n "$new_char" >> flag.txt

  generate_flag
}

if [ ! -f flag.txt ]; then
  echo "" > flag.txt
fi

generate_flag

if [ -f flag.txt ]; then
  rm flag.txt
fi
