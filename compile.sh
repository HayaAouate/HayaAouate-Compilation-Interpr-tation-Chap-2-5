#!/bin/bash
cd /mnt/c/Users/Aouat/Desktop/TexIEDP8

echo "Killing any running xelatex processes..."
pkill -9 xelatex 2>/dev/null

echo "Cleaning build directory..."
rm -rf build/*

echo "Pass 1/3..."
xelatex -output-directory=build -interaction=batchmode main.tex

echo "Pass 2/3..."
xelatex -output-directory=build -interaction=batchmode main.tex

echo "Pass 3/3..."
xelatex -output-directory=build -interaction=batchmode main.tex

if [ -f build/main.pdf ]; then
    SIZE=$(du -h build/main.pdf | cut -f1)
    PAGES=$(pdfinfo build/main.pdf 2>/dev/null | grep Pages | awk '{print $2}')
    echo ""
    echo "✓ SUCCESS: PDF created"
    echo "  Size: $SIZE"
    echo "  Pages: ${PAGES:-unknown}"
    echo "  Path: build/main.pdf"
else
    echo "✗ FAILED: No PDF generated"
    exit 1
fi
