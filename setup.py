from setuptools import setup, Extension

with open('README.md', 'r') as f:
    longdesc = f.read()

unshare_module = Extension('unshare', ['unshare.c'])

setup(
    name = 'unshare', 
    version = 0.22, 
    author = 'Shubham Sharma',
    author_email = 'shubhamsharma1172@gmail.com',
    description = 'Python extension for C\'s unshare call (man 2 unshare)',
    long_description = longdesc,
    long_description_content_type = 'text/markdown',
    url = 'https://github.com/shubham1172/unshare',
    license = 'GPLv3',
    platforms = 'Linux',
    keywords = ['Linux', 'unshare', 'system'],
    ext_modules = [unshare_module])
