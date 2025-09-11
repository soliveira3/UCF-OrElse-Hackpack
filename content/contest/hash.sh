# Hashes a file, ignoring all whitespace and comments. Use for
# verifying that code was correctly typed.
# Use chmod +x hash.sh
# Then ./hash.sh < ./fileName
cpp -dD -P -fpreprocessed | tr -d '[:space:]'| md5sum |cut -c-6
