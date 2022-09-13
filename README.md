# unshare

[![PyPI](https://img.shields.io/pypi/v/unshare.svg?color=green&logo=unshare&style=plastic)](https://pypi.org/project/unshare/)


```bash
pip3 install unshare
```

<hr>

Python extension for C's unshare call. <br>
See [man 2 unshare](http://man7.org/linux/man-pages/man2/unshare.2.html).


**Note**: This is targeted for only Linux based platforms.


# Usage

`unshare(flags)` where supported flags are `CLONE_NEWNS`, `CLONE_NEWUTS`, `CLONE_NEWPID`, `CLONE_NEWUSER`, `CLONE_NEWIPC`, `CLONE_NEWNET`, `CLONE_THREAD`. <br>
Multiple flags can be used using the bitwise or operator.

# Example usage

```python3
import unshare
unshare.unshare(unshare.CLONE_NEWUTS)
```

The following screenshot is taken from [a sample script](https://gist.github.com/shubham1172/7c53130e6e0258f998f331955564dc4c#file-container-py) which uses the unshare library.

![](https://i.imgur.com/B8X0LT8.png)

See [shubham1172/pocket](https://github.com/shubham1172/pocket) for a tiny python container runtime using this library.

# License

This project is licensed under [GPLv3](./LICENSE).
