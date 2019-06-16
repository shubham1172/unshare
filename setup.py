from distutils.core import setup, Extension

unshare_module = Extension('unshare', ['unshare.c'])

setup(
    name = 'unshare', 
    version = 0.1, 
    author = 'Shubham Sharma',
    author_email = 'shubhamsharma1172@gmail.com',
    description = 'Python extension for C\'s unshare call (man 2 unshare)',
    url = 'https://github.com/shubham1172/unshare',
    license = 'GPLv3',
    platforms = 'Linux',
    keywords = ['Linux', 'unshare', 'system'],
    ext_modules = [unshare_module])
